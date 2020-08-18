/*
 * QEMU model of the XPPU xppu
 *
 * Copyright (c) 2020 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2020-01-13.
 * Written by: Joe Komlodi <komlodi@xilinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "hw/irq.h"
#include "qapi/error.h"
#include "qemu/log.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"

#include "hw/fdt_generic_util.h"
#include "hw/misc/xlnx-xppu.h"

bool parity32(uint32_t v)
{
    /*
     * We compute the parity in parallel, folding
     * each result in half, all the way down to one last bit.
     */
    v = v ^ (v >> 16);
    v = v ^ (v >> 8);
    v = v ^ (v >> 4);
    v = v ^ (v >> 2);
    v = v ^ (v >> 1);
    return v & 1;
}

bool check_mid_parity(XPPU *s, uint32_t val32)
{
    const uint32_t rsvd = 0x3c00fc00;
    bool p_written;
    bool p_computed;

    if (!ARRAY_FIELD_EX32(s->regs, CTRL, MID_PARITY_EN)) {
        return true;
    }

    /* Save the written parity. */
    p_written = val32 & 0x80000000;

    /* Mask off parity field. */
    val32 &= ~0x80000000;
    /* Mask off rsvd fields. */
    val32 &= ~rsvd;
    p_computed = parity32(val32);

    return p_written == p_computed;
}

void check_mid_parities(XPPU *s)
{
    unsigned int i;

    for (i = 0; i < NR_MID_ENTRIES; i++) {
        uint32_t val32;

        val32 = s->regs[R_MASTER_ID00 + i];

        /* Check MID parity. */
        if (check_mid_parity(s, val32) == false) {
            ARRAY_FIELD_DP32(s->regs, ISR, MID_PARITY, true);
            continue;
        }
    }
}

bool check_apl_parity(XPPU *s, uint32_t val32)
{
    unsigned int i;
    /*
     * Bit 31 - Parity of 27, 19:15.
     * Bit 30 - Parity of 14:10
     * Bit 29 - Parity of 9:5
     * Bit 28 - Parity of 4:0
     */
     const uint32_t apl_parities[] = {
        0x1f,
        0x1f << 5,
        0x1f << 10,
        (0x1f << 15) | 1 << 27,
    };
    uint32_t p = 0, p_written;
    bool ok;

    if (!ARRAY_FIELD_EX32(s->regs, CTRL, APER_PARITY_EN)) {
        return true;
    }

    for (i = 0; i < ARRAY_SIZE(apl_parities); i++) {
        uint32_t v = val32;
        bool parity;

        /* Extract the lanes for this pairity.  */
        v &= apl_parities[i];
        parity = parity32(v);
        p |= ((int) parity) << i;
    }

    p_written = val32 >> 28;
    ok = p_written == p;

    if (!ok) {
        qemu_log_mask(LOG_GUEST_ERROR, "Bad APL parity!\n");
        ARRAY_FIELD_DP32(s->regs, ISR, APER_PARITY, true);
    }
    return ok;
}

void update_mrs(XPPU *s)
{
    bool xppu_enabled = ARRAY_FIELD_EX32(s->regs, CTRL, ENABLE);
    unsigned int i;

    for (i = 0; i < s->num_ap; i++) {
        memory_region_set_enabled(&s->ap[i].iomem, xppu_enabled);
    }
}

bool xppu_ap_check(XPPU *s, MemTxAttrs attr, bool rw, uint32_t apl)
{
    unsigned int i;
    bool mid_match = false;
    bool tz = extract32(apl, 27, 1);
    bool ok;

    ok = check_apl_parity(s, apl);
    if (!ok) {
        return false;
    }

    /* Check MIDs. */
    for (i = 0; i < NR_MID_ENTRIES; i++) {
        uint32_t val32, mid, mask;
        bool readonly;

        if (!extract32(apl, i, 1)) {
            continue;
        }

        val32 = s->regs[R_MASTER_ID00 + i];
        mid = FIELD_EX32(val32, MASTER_ID00, MID);
        readonly = FIELD_EX32(val32, MASTER_ID00, MIDR);
        mask = FIELD_EX32(val32, MASTER_ID00, MIDM);

        if ((mid & mask) != (attr.requester_id & mask)) {
            continue;
        }

        mid_match = true;

        /* Check MID parity.  */
        if (check_mid_parity(s, val32) == false) {
            ARRAY_FIELD_DP32(s->regs, ISR, MID_PARITY, true);
            continue;
        }

        if (readonly && rw) {
            ARRAY_FIELD_DP32(s->regs, ISR, MID_RO, true);
            continue;
        }

        if (!attr.secure && !tz) {
            ARRAY_FIELD_DP32(s->regs, ISR, APER_TZ, true);
            continue;
        }

        break;
    }

    if (!mid_match) {
        /* Set if MID checks don't make it past masking and compare. */
        ARRAY_FIELD_DP32(s->regs, ISR, MID_MISS, true);
    }

    return i < NR_MID_ENTRIES;
}

void isr_update_irq(XPPU *s)
{
    bool pending = s->regs[R_ISR] & ~s->regs[R_IMR];
    qemu_set_irq(s->irq_isr, pending);
}

MemTxResult xppu_read_common(void *opaque, XPPU *s, hwaddr addr, uint64_t *val,
                             unsigned size, MemTxAttrs attr)
{
    RegisterInfo *r;

    r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log_mask(LOG_GUEST_ERROR, "%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        ARRAY_FIELD_DP32(s->regs, ISR, INV_APB, true);
        isr_update_irq(s);
        return MEMTX_DECODE_ERROR;
    }

    *val = register_read_memory(opaque, addr, size);
    return MEMTX_OK;
}

MemTxResult xppu_write_common(void *opaque, XPPU *s, hwaddr addr, uint64_t val,
                              unsigned size, MemTxAttrs attr)
{
    RegisterInfo *r;

    if (!attr.secure) {
        return MEMTX_ERROR;
    }

    r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log_mask(LOG_GUEST_ERROR, "%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, val);
        ARRAY_FIELD_DP32(s->regs, ISR, INV_APB, true);
        isr_update_irq(s);
        return MEMTX_DECODE_ERROR;
    }

    register_write_memory(opaque, addr, val, size);
    return MEMTX_OK;
}

MemTxResult xppu_perm_ram_write_common(XPPU *s, hwaddr addr, uint64_t val,
                                       unsigned size, MemTxAttrs attr)
{
    unsigned int i;

    if (!attr.secure) {
        return MEMTX_ERROR;
    }

    i = addr / 4;
    if (i >= ARRAY_SIZE(s->perm_ram)) {
        qemu_log("%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, val);
        ARRAY_FIELD_DP32(s->regs, ISR, INV_APB, true);
        isr_update_irq(s);
        return MEMTX_DECODE_ERROR;
    }

    s->perm_ram[i] = val;
    return MEMTX_OK;
}

MemTxResult xppu_perm_ram_read_common(XPPU *s, hwaddr addr, uint64_t *val,
                                      unsigned size, MemTxAttrs attr)
{
    unsigned int i;

    i = addr / 4;
    if (i >= ARRAY_SIZE(s->perm_ram)) {
        qemu_log("%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        ARRAY_FIELD_DP32(s->regs, ISR, INV_APB, true);
        isr_update_irq(s);
        return MEMTX_DECODE_ERROR;
    }

    *val = s->perm_ram[i];
    return MEMTX_OK;
}

void xppu_init_common(XPPU *s, Object *obj, const char *tn,
                      const MemoryRegionOps *ops, const MemoryRegionOps *pr_ops,
                      const RegisterAccessInfo *regs_info, size_t regs_info_sz)
{
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init_io(&s->iomem, obj, ops, s, tn, 0x10000);
    memory_region_init_io(&s->perm_ram_iomem, obj, pr_ops, s, tn, 0xE000);
    reg_array =
        register_init_block32(DEVICE(obj), regs_info,
                              regs_info_sz,
                              s->regs_info, s->regs,
                              ops,
                              XILINX_XPPU_ERR_DEBUG,
                              XPPU_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    memory_region_add_subregion(&s->iomem, 0x1000, &s->perm_ram_iomem);
    sysbus_init_mmio(sbd, &s->iomem);
    object_property_add_link(obj, "mr", TYPE_MEMORY_REGION,
                             (Object **)&s->mr,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_STRONG);

    sysbus_init_irq(sbd, &s->irq_isr);
}

bool xppu_parse_reg_common(XPPU *s, const char *tn, FDTGenericRegPropInfo reg,
                           FDTGenericMMap *obj, const XPPUApertureInfo *ap_info,
                           const MemoryRegionOps *ap_ops, Error **errp)
{
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    ObjectClass *klass = object_class_by_name(tn);
    FDTGenericMMapClass *parent_fmc;
    unsigned int i;
    char *name;

    parent_fmc = FDT_GENERIC_MMAP_CLASS(object_class_get_parent(klass));
    for (i = 0; i < (reg.n - 1) && i < s->num_ap; i++) {
        s->ap[i].parent = s;
        s->ap[i].granule = ap_info->granules[i];
        s->ap[i].base = ap_info->bases[i];
        s->ap[i].extract_mask = ap_info->masks[i];
        s->ap[i].extract_shift = ap_info->shifts[i];
        s->ap[i].ram_base = ap_info->ram_bases[i];

        name = g_strdup_printf("xppu-mr-%d\n", i);
        memory_region_init_io(&s->ap[i].iomem, OBJECT(obj),
                              ap_ops, &s->ap[i], name, reg.s[i + 1]);
        sysbus_init_mmio(sbd, &s->ap[i].iomem);
        g_free(name);
    }

    return parent_fmc ? parent_fmc->parse_reg(obj, reg, errp) : false;
}
