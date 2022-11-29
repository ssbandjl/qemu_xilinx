/*
 * QEMU model of the PMU_LOCAL Power Management Unit Local Register File
 *
 * Copyright (c) 2014-2020 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2014-09-01.
 * Written by Edgar E. Iglesias.
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
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"

#include "hw/fdt_generic_util.h"

#ifndef XILINX_PMU_LOCAL_ERR_DEBUG
#define XILINX_PMU_LOCAL_ERR_DEBUG 0
#endif

#define TYPE_XILINX_PMU_LOCAL "xlnx.pmu-local"

#define XILINX_PMU_LOCAL(obj) \
     OBJECT_CHECK(PMULocal, (obj), TYPE_XILINX_PMU_LOCAL)


REG32(ACPU0_PWR_CNTRL, 0x0)
    FIELD(ACPU0_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(ACPU0_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(ACPU0_PWR_STATUS, 0x4)
    FIELD(ACPU0_PWR_STATUS, PWR_GATES, 0, 4)
REG32(ACPU1_PWR_CNTRL, 0x10)
    FIELD(ACPU1_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(ACPU1_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(ACPU1_PWR_STATUS, 0x14)
    FIELD(ACPU1_PWR_STATUS, PWR_GATES, 0, 4)
REG32(ACPU2_PWR_CNTRL, 0x20)
    FIELD(ACPU2_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(ACPU2_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(ACPU2_PWR_STATUS, 0x24)
    FIELD(ACPU2_PWR_STATUS, PWR_GATES, 0, 4)
REG32(ACPU3_PWR_CNTRL, 0x30)
    FIELD(ACPU3_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(ACPU3_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(ACPU3_PWR_STATUS, 0x34)
    FIELD(ACPU3_PWR_STATUS, PWR_GATES, 0, 4)
REG32(PP0_PWR_CNTRL, 0x40)
    FIELD(PP0_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(PP0_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(PP0_PWR_STATUS, 0x44)
    FIELD(PP0_PWR_STATUS, PWR_GATES, 0, 4)
REG32(PP1_PWR_CNTRL, 0x48)
    FIELD(PP1_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(PP1_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(PP1_PWR_STATUS, 0x4c)
    FIELD(PP1_PWR_STATUS, PWR_GATES, 0, 4)
REG32(USB0_PWR_CNTRL, 0x60)
    FIELD(USB0_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(USB0_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(USB0_PWR_STATUS, 0x64)
    FIELD(USB0_PWR_STATUS, PWR_GATES, 0, 4)
REG32(USB1_PWR_CNTRL, 0x70)
    FIELD(USB1_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(USB1_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(USB1_PWR_STATUS, 0x74)
    FIELD(USB1_PWR_STATUS, PWR_GATES, 0, 4)
REG32(RPU_PWR_CNTRL, 0x80)
    FIELD(RPU_PWR_CNTRL, ISOLATION, 4, 1)
    FIELD(RPU_PWR_CNTRL, PWR_GATES, 0, 4)
REG32(RPU_PWR_STATUS, 0x84)
    FIELD(RPU_PWR_STATUS, PWR_GATES, 0, 4)
REG32(L2_PWR_CNTRL, 0xb0)
    FIELD(L2_PWR_CNTRL, BANK0, 0, 1)
REG32(L2_RET_CNTRL, 0xb4)
    FIELD(L2_RET_CNTRL, BANK0, 0, 1)
REG32(L2_CE_CNTRL, 0xb8)
    FIELD(L2_CE_CNTRL, BANK0, 0, 1)
REG32(L2_PWR_STATUS, 0xbc)
    FIELD(L2_PWR_STATUS, BANK0, 0, 1)
REG32(OCM_PWR_CNTRL, 0xc0)
    FIELD(OCM_PWR_CNTRL, BANK3, 24, 1)
    FIELD(OCM_PWR_CNTRL, BANK2, 16, 1)
    FIELD(OCM_PWR_CNTRL, BANK1, 8, 1)
    FIELD(OCM_PWR_CNTRL, BANK0, 0, 1)
REG32(OCM_RET_CNTRL, 0xc4)
    FIELD(OCM_RET_CNTRL, BANK3, 3, 1)
    FIELD(OCM_RET_CNTRL, BANK2, 2, 1)
    FIELD(OCM_RET_CNTRL, BANK1, 1, 1)
    FIELD(OCM_RET_CNTRL, BANK0, 0, 1)
REG32(OCM_CE_CNTRL, 0xc8)
    FIELD(OCM_CE_CNTRL, BANK3, 3, 1)
    FIELD(OCM_CE_CNTRL, BANK2, 2, 1)
    FIELD(OCM_CE_CNTRL, BANK1, 1, 1)
    FIELD(OCM_CE_CNTRL, BANK0, 0, 1)
REG32(OCM_PWR_STATUS, 0xcc)
    FIELD(OCM_PWR_STATUS, BANK3, 24, 1)
    FIELD(OCM_PWR_STATUS, BANK2, 16, 1)
    FIELD(OCM_PWR_STATUS, BANK1, 8, 1)
    FIELD(OCM_PWR_STATUS, BANK0, 0, 1)
REG32(TCM_PWR_CNTRL, 0xd0)
    FIELD(TCM_PWR_CNTRL, TCMB1, 24, 1)
    FIELD(TCM_PWR_CNTRL, TCMA1, 16, 1)
    FIELD(TCM_PWR_CNTRL, TCMB0, 8, 1)
    FIELD(TCM_PWR_CNTRL, TCMA0, 0, 1)
REG32(TCM_RET_CNTRL, 0xd4)
    FIELD(TCM_RET_CNTRL, TCMB1, 3, 1)
    FIELD(TCM_RET_CNTRL, TCMA1, 2, 1)
    FIELD(TCM_RET_CNTRL, TCMB0, 1, 1)
    FIELD(TCM_RET_CNTRL, TCMA0, 0, 1)
REG32(TCM_CE_CNTRL, 0xd8)
    FIELD(TCM_CE_CNTRL, TCMB1, 3, 1)
    FIELD(TCM_CE_CNTRL, TCMA1, 2, 1)
    FIELD(TCM_CE_CNTRL, TCMB0, 1, 1)
    FIELD(TCM_CE_CNTRL, TCMA0, 0, 1)
REG32(TCM_PWR_STATUS, 0xdc)
    FIELD(TCM_PWR_STATUS, TCMB1, 24, 1)
    FIELD(TCM_PWR_STATUS, TCMA1, 16, 1)
    FIELD(TCM_PWR_STATUS, TCMB0, 8, 1)
    FIELD(TCM_PWR_STATUS, TCMA0, 0, 1)
REG32(DOMAIN_ISO_CNTRL, 0xf0)
    FIELD(DOMAIN_ISO_CNTRL, LP_FP_LOCKED, 31, 1)
    FIELD(DOMAIN_ISO_CNTRL, FP_PL, 5, 1)
    FIELD(DOMAIN_ISO_CNTRL, LP_PL_PCAP, 4, 1)
    FIELD(DOMAIN_ISO_CNTRL, LP_PL_NON_PCAP, 3, 1)
    FIELD(DOMAIN_ISO_CNTRL, LP_FP_2, 2, 1)
    FIELD(DOMAIN_ISO_CNTRL, LP_FP_1, 1, 1)
    FIELD(DOMAIN_ISO_CNTRL, PMU, 0, 1)
REG32(LOC_PWR_STATE, 0x100)
    FIELD(LOC_PWR_STATE, USB1, 21, 1)
    FIELD(LOC_PWR_STATE, USB0, 20, 1)
    FIELD(LOC_PWR_STATE, OCM_BANK3, 19, 1)
    FIELD(LOC_PWR_STATE, OCM_BANK2, 18, 1)
    FIELD(LOC_PWR_STATE, OCM_BANK1, 17, 1)
    FIELD(LOC_PWR_STATE, OCM_BANK0, 16, 1)
    FIELD(LOC_PWR_STATE, TCM1B, 15, 1)
    FIELD(LOC_PWR_STATE, TCM1A, 14, 1)
    FIELD(LOC_PWR_STATE, TCM0B, 13, 1)
    FIELD(LOC_PWR_STATE, TCM0A, 12, 1)
    FIELD(LOC_PWR_STATE, R5_1, 11, 1)
    FIELD(LOC_PWR_STATE, R5_0, 10, 1)
    FIELD(LOC_PWR_STATE, L2, 7, 1)
    FIELD(LOC_PWR_STATE, GPU_PP1, 5, 1)
    FIELD(LOC_PWR_STATE, GPU_PP0, 4, 1)
    FIELD(LOC_PWR_STATE, ACPU3, 3, 1)
    FIELD(LOC_PWR_STATE, ACPU2, 2, 1)
    FIELD(LOC_PWR_STATE, ACPU1, 1, 1)
    FIELD(LOC_PWR_STATE, ACPU0, 0, 1)
REG32(LOC_AUX_PWR_STATE, 0x104)
    FIELD(LOC_AUX_PWR_STATE, ACPU3_EMUL, 31, 1)
    FIELD(LOC_AUX_PWR_STATE, ACPU2_EMUL, 30, 1)
    FIELD(LOC_AUX_PWR_STATE, ACPU1_EMUL, 29, 1)
    FIELD(LOC_AUX_PWR_STATE, ACPU0_EMUL, 28, 1)
    FIELD(LOC_AUX_PWR_STATE, RPU_EMUL, 27, 1)
    FIELD(LOC_AUX_PWR_STATE, OCM_BANK3, 19, 1)
    FIELD(LOC_AUX_PWR_STATE, OCM_BANK2, 18, 1)
    FIELD(LOC_AUX_PWR_STATE, OCM_BANK1, 17, 1)
    FIELD(LOC_AUX_PWR_STATE, OCM_BANK0, 16, 1)
    FIELD(LOC_AUX_PWR_STATE, TCM1B, 15, 1)
    FIELD(LOC_AUX_PWR_STATE, TCM1A, 14, 1)
    FIELD(LOC_AUX_PWR_STATE, TCM0B, 13, 1)
    FIELD(LOC_AUX_PWR_STATE, TCM0A, 12, 1)
    FIELD(LOC_AUX_PWR_STATE, L2, 7, 1)
REG32(LOCAL_RESET, 0x200)
    FIELD(LOCAL_RESET, CSU_RST, 0, 1)
REG32(LOCAL_CNTRL, 0x204)
    FIELD(LOCAL_CNTRL, ROM_VALID_OVRD, 1, 1)
    FIELD(LOCAL_CNTRL, BUS_CLK_DIS, 0, 1)
REG32(GPO1_READ, 0x214)
    FIELD(GPO1_READ, MIO_GPO, 0, 6)
REG32(GPO2_READ, 0x218)
    FIELD(GPO2_READ, DAP_RPU_WAKE_ACK, 9, 1)
    FIELD(GPO2_READ, DAP_FP_WAKE_ACK, 8, 1)
    FIELD(GPO2_READ, PS_STATUS, 7, 1)
    FIELD(GPO2_READ, PCAP_ENABLE, 6, 1)
REG32(GPO3_READ, 0x21c)
REG32(GPI1_ENABLE, 0x224)
    FIELD(GPI1_ENABLE, APB_AIB_ERROR, 31, 1)
    FIELD(GPI1_ENABLE, AXI_AIB_ERROR, 30, 1)
    FIELD(GPI1_ENABLE, ERROR_REG2_INT, 29, 1)
    FIELD(GPI1_ENABLE, ERROR_REG1_INT, 28, 1)
    FIELD(GPI1_ENABLE, DBG_ACPU3_PWRUP_REQ, 23, 1)
    FIELD(GPI1_ENABLE, DBG_ACPU2_PWRUP_REQ, 22, 1)
    FIELD(GPI1_ENABLE, DBG_ACPU1_PWRUP_REQ, 21, 1)
    FIELD(GPI1_ENABLE, DBG_ACPU0_PWRUP_REQ, 20, 1)
    FIELD(GPI1_ENABLE, FPD_WAKE_GIC_PROX, 16, 1)
    FIELD(GPI1_ENABLE, MIO_WAKE, 10, 6)
    FIELD(GPI1_ENABLE, DAP_RPU_WAKE, 9, 1)
    FIELD(GPI1_ENABLE, DAP_FP_WAKE, 8, 1)
    FIELD(GPI1_ENABLE, USB1_WAKE, 7, 1)
    FIELD(GPI1_ENABLE, USB0_WAKE, 6, 1)
    FIELD(GPI1_ENABLE, R5_1_WAKE, 5, 1)
    FIELD(GPI1_ENABLE, R5_0_WAKE, 4, 1)
    FIELD(GPI1_ENABLE, ACPU3_WAKE, 3, 1)
    FIELD(GPI1_ENABLE, ACPU2_WAKE, 2, 1)
    FIELD(GPI1_ENABLE, ACPU1_WAKE, 1, 1)
    FIELD(GPI1_ENABLE, ACPU0_WAKE, 0, 1)
REG32(GPI2_ENABLE, 0x228)
    FIELD(GPI2_ENABLE, VCC_PSINTFP_ALARM, 31, 1)
    FIELD(GPI2_ENABLE, VCC_PSINT_ALARM, 30, 1)
    FIELD(GPI2_ENABLE, VCC_PSAUX_ALARM, 29, 1)
    FIELD(GPI2_ENABLE, DBG_ACPU3_RST_REQ, 23, 1)
    FIELD(GPI2_ENABLE, DBG_ACPU2_RST_REQ, 22, 1)
    FIELD(GPI2_ENABLE, DBG_ACPU1_RST_REQ, 21, 1)
    FIELD(GPI2_ENABLE, DBG_ACPU0_RST_REQ, 20, 1)
    FIELD(GPI2_ENABLE, CP_ACPU3_RST_REQ, 19, 1)
    FIELD(GPI2_ENABLE, CP_ACPU2_RST_REQ, 18, 1)
    FIELD(GPI2_ENABLE, CP_ACPU1_RST_REQ, 17, 1)
    FIELD(GPI2_ENABLE, CP_ACPU0_RST_REQ, 16, 1)
    FIELD(GPI2_ENABLE, DBG_RPU1_RST_REQ, 9, 1)
    FIELD(GPI2_ENABLE, DBG_RPU0_RST_REQ, 8, 1)
    FIELD(GPI2_ENABLE, FP_LP_PWRDWN_ACK, 6, 1)
    FIELD(GPI2_ENABLE, R5_1_PWRDWN_REQ, 5, 1)
    FIELD(GPI2_ENABLE, R5_0_PWRDWN_REQ, 4, 1)
    FIELD(GPI2_ENABLE, ACPU3_PWRDWN_REQ, 3, 1)
    FIELD(GPI2_ENABLE, ACPU2_PWRDWN_REQ, 2, 1)
    FIELD(GPI2_ENABLE, ACPU1_PWRDWN_REQ, 1, 1)
    FIELD(GPI2_ENABLE, ACPU0_PWRDWN_REQ, 0, 1)
REG32(GPI3_ENABLE, 0x22c)
REG32(LOCAL_GEN_STORAGE0, 0x300)
REG32(LOCAL_GEN_STORAGE1, 0x304)
REG32(LOCAL_GEN_STORAGE2, 0x308)
REG32(LOCAL_GEN_STORAGE3, 0x30c)
REG32(PERS_LOC_GEN_STORAGE0, 0x310)
REG32(PERS_LOC_GEN_STORAGE1, 0x314)
REG32(PERS_LOC_GEN_STORAGE2, 0x318)
REG32(PERS_LOC_GEN_STORAGE3, 0x31c)
REG32(ADDR_ERROR_STATUS, 0x320)
    FIELD(ADDR_ERROR_STATUS, STATUS, 0, 1)
REG32(ADDR_ERROR_INT_MASK, 0x324)
    FIELD(ADDR_ERROR_INT_MASK, MASK, 0, 1)
REG32(ADDR_ERROR_INT_EN, 0x328)
    FIELD(ADDR_ERROR_INT_EN, EN, 0, 1)
REG32(ADDR_ERROR_INT_DIS, 0x32c)
    FIELD(ADDR_ERROR_INT_DIS, _, 0, 1)
REG32(MBISR_CNTRL, 0x330)
    FIELD(MBISR_CNTRL, FPD_GROUP, 5, 1)
    FIELD(MBISR_CNTRL, ENABLE, 0, 1)
REG32(MBISR_STATUS, 0x334)
    FIELD(MBISR_STATUS, PASS, 4, 1)
    FIELD(MBISR_STATUS, DONE, 0, 1)
REG32(PMU_PB_ERR, 0x338)
    FIELD(PMU_PB_ERR, PBERR_FLAG, 31, 1)
    FIELD(PMU_PB_ERR, PBERR_DATA, 0, 31)
REG32(PMU_SERV_ERR, 0x33c)
    FIELD(PMU_SERV_ERR, FWERR, 28, 4)
    FIELD(PMU_SERV_ERR, SERVERR_FLAG, 23, 1)
    FIELD(PMU_SERV_ERR, SERVERR_DATA, 0, 20)
REG32(PWR_ACK_ERR_LPD, 0x340)
REG32(PWR_ACK_ERR_FPD, 0x344)
REG32(SERV_LOGCLR_ERR, 0x348)
REG32(LOGCLR_TRIG, 0x350)
    FIELD(LOGCLR_TRIG, FP, 17, 1)
    FIELD(LOGCLR_TRIG, LP, 16, 1)
    FIELD(LOGCLR_TRIG, USB1, 13, 1)
    FIELD(LOGCLR_TRIG, USB0, 12, 1)
    FIELD(LOGCLR_TRIG, RPU, 10, 1)
    FIELD(LOGCLR_TRIG, PP1, 7, 1)
    FIELD(LOGCLR_TRIG, PP0, 6, 1)
    FIELD(LOGCLR_TRIG, ACPU3, 3, 1)
    FIELD(LOGCLR_TRIG, ACPU2, 2, 1)
    FIELD(LOGCLR_TRIG, ACPU1, 1, 1)
    FIELD(LOGCLR_TRIG, ACPU0, 0, 1)
REG32(LOGCLR_ACK, 0x354)
    FIELD(LOGCLR_ACK, FP, 17, 1)
    FIELD(LOGCLR_ACK, LP, 16, 1)
    FIELD(LOGCLR_ACK, USB1, 13, 1)
    FIELD(LOGCLR_ACK, USB0, 12, 1)
    FIELD(LOGCLR_ACK, RPU, 10, 1)
    FIELD(LOGCLR_ACK, PP1, 7, 1)
    FIELD(LOGCLR_ACK, PP0, 6, 1)
    FIELD(LOGCLR_ACK, ACPU3, 3, 1)
    FIELD(LOGCLR_ACK, ACPU2, 2, 1)
    FIELD(LOGCLR_ACK, ACPU1, 1, 1)
    FIELD(LOGCLR_ACK, ACPU0, 0, 1)
REG32(APU_WFI_STATUS, 0x360)
    FIELD(APU_WFI_STATUS, L2_WFI, 16, 1)
    FIELD(APU_WFI_STATUS, ACPU3_WFI, 3, 1)
    FIELD(APU_WFI_STATUS, ACPU2_WFI, 2, 1)
    FIELD(APU_WFI_STATUS, ACPU1_WFI, 1, 1)
    FIELD(APU_WFI_STATUS, ACPU0_WFI, 0, 1)
REG32(MBIST_RST, 0x36c)
    FIELD(MBIST_RST, CSU, 1, 1)
    FIELD(MBIST_RST, PMU, 0, 1)
REG32(MBIST_PG_EN, 0x370)
    FIELD(MBIST_PG_EN, CSU, 1, 1)
    FIELD(MBIST_PG_EN, PMU, 0, 1)
REG32(MBIST_SETUP, 0x374)
    FIELD(MBIST_SETUP, CSU, 1, 1)
    FIELD(MBIST_SETUP, PMU, 0, 1)
REG32(MBIST_DONE, 0x378)
    FIELD(MBIST_DONE, CSU, 1, 1)
    FIELD(MBIST_DONE, PMU, 0, 1)
REG32(MBIST_GOOD, 0x37c)
    FIELD(MBIST_GOOD, CSU, 1, 1)
    FIELD(MBIST_GOOD, PMU, 0, 1)
REG32(ECO_1, 0x400)
REG32(ECO_2, 0x404)

#define PMU_LOCAL_R_MAX (R_ECO_2 + 1)

typedef struct PMULocal {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_addr_error_int;

    qemu_irq rst_csu;
    qemu_irq pwr_acpu[4];
    qemu_irq pwr_pp[2];
    qemu_irq pwr_usb[2];
    qemu_irq pwr_rpu;
    qemu_irq pwr_l2;
    qemu_irq ret_l2;
    qemu_irq pwr_ocm[4];
    qemu_irq ret_ocm[4];
    qemu_irq pwr_tcm_a[2];
    qemu_irq pwr_tcm_b[2];
    qemu_irq ret_tcm_a[2];
    qemu_irq ret_tcm_b[2];
    qemu_irq fpd_pwr_cntrl;
    qemu_irq gpi_enable[2];

    uint32_t regs[PMU_LOCAL_R_MAX];
    RegisterInfo regs_info[PMU_LOCAL_R_MAX];
} PMULocal;

#define PROPAGATE_GPIO(s, reg, f, irq) {                         \
    bool val = ARRAY_FIELD_EX32((s)->regs, reg, f);              \
    qemu_set_irq(irq, val);                                      \
}

#define PROPAGATE_FIELD1(s, sreg, sf, dreg, df, irq) {           \
    unsigned int val = ARRAY_FIELD_EX32((s)->regs, sreg, sf);    \
    ARRAY_FIELD_DP32((s)->regs, dreg, df, val);                  \
    qemu_set_irq(irq, val);                                      \
}

static void addr_error_int_update_irq(PMULocal *s)
{
    bool pending = s->regs[R_ADDR_ERROR_STATUS] & ~s->regs[R_ADDR_ERROR_INT_MASK];
    qemu_set_irq(s->irq_addr_error_int, pending);
}

static void addr_error_status_postw(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);
    addr_error_int_update_irq(s);
}

static uint64_t addr_error_int_en_prew(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_ADDR_ERROR_INT_MASK] &= ~val;
    addr_error_int_update_irq(s);
    return 0;
}

static uint64_t addr_error_int_dis_prew(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_ADDR_ERROR_INT_MASK] |= val;
    addr_error_int_update_irq(s);
    return 0;
}

struct PwrStateMap {
    bool end;
    uint64_t addr;
    uint32_t mask;
    unsigned int bit;
    bool xor;
};

static struct {
    bool end;
    uint64_t addr;
    unsigned int bit;
    uint32_t mask;
    struct PwrStateMap *map;
} power_reg_map [] = {
    {   .addr = A_ACPU0_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_ACPU0_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_ACPU1_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_ACPU1_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_ACPU2_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_ACPU2_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_ACPU3_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_ACPU3_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_PP0_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_PP0_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_PP1_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_PP1_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_USB0_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_USB0_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_USB1_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_USB1_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    {   .addr = A_RPU_PWR_CNTRL, .bit = 0, .mask = 0xf,
        .map = (struct PwrStateMap[]) {
            { .addr = A_RPU_PWR_STATUS, .bit = 0 },
            { .end = true }
        }
    },
    { .end = true }
};

static void update_gpios(PMULocal *s)
{
    /*
     * This must be called after propagating the PWR Controls to
     * the PWR STATUS fields.
     */
    PROPAGATE_GPIO(s, LOCAL_RESET, CSU_RST, s->rst_csu);

    PROPAGATE_GPIO(s, ACPU0_PWR_STATUS, PWR_GATES, s->pwr_acpu[0]);
    PROPAGATE_GPIO(s, ACPU1_PWR_STATUS, PWR_GATES, s->pwr_acpu[1]);
    PROPAGATE_GPIO(s, ACPU2_PWR_STATUS, PWR_GATES, s->pwr_acpu[2]);
    PROPAGATE_GPIO(s, ACPU3_PWR_STATUS, PWR_GATES, s->pwr_acpu[3]);

    PROPAGATE_GPIO(s, PP0_PWR_STATUS, PWR_GATES, s->pwr_pp[0]);
    PROPAGATE_GPIO(s, PP1_PWR_STATUS, PWR_GATES, s->pwr_pp[1]);

    PROPAGATE_GPIO(s, USB0_PWR_STATUS, PWR_GATES, s->pwr_usb[0]);
    PROPAGATE_GPIO(s, USB1_PWR_STATUS, PWR_GATES, s->pwr_usb[1]);

    PROPAGATE_FIELD1(s, L2_PWR_CNTRL, BANK0,
                     L2_PWR_STATUS, BANK0, s->pwr_l2);
    PROPAGATE_GPIO(s, L2_RET_CNTRL, BANK0, s->ret_l2);

    PROPAGATE_FIELD1(s, OCM_PWR_CNTRL, BANK0,
                     OCM_PWR_STATUS, BANK0, s->pwr_ocm[0]);
    PROPAGATE_FIELD1(s, OCM_PWR_CNTRL, BANK1,
                     OCM_PWR_STATUS, BANK1, s->pwr_ocm[1]);
    PROPAGATE_FIELD1(s, OCM_PWR_CNTRL, BANK2,
                     OCM_PWR_STATUS, BANK2, s->pwr_ocm[2]);
    PROPAGATE_FIELD1(s, OCM_PWR_CNTRL, BANK3,
                     OCM_PWR_STATUS, BANK3, s->pwr_ocm[3]);

    PROPAGATE_GPIO(s, OCM_RET_CNTRL, BANK0, s->ret_ocm[0]);
    PROPAGATE_GPIO(s, OCM_RET_CNTRL, BANK1, s->ret_ocm[1]);
    PROPAGATE_GPIO(s, OCM_RET_CNTRL, BANK2, s->ret_ocm[2]);
    PROPAGATE_GPIO(s, OCM_RET_CNTRL, BANK3, s->ret_ocm[3]);

    PROPAGATE_FIELD1(s, TCM_PWR_CNTRL, TCMA0,
                     TCM_PWR_STATUS, TCMA0, s->pwr_tcm_a[0]);
    PROPAGATE_FIELD1(s, TCM_PWR_CNTRL, TCMB0,
                     TCM_PWR_STATUS, TCMB0, s->pwr_tcm_b[0]);
    PROPAGATE_FIELD1(s, TCM_PWR_CNTRL, TCMA1,
                     TCM_PWR_STATUS, TCMA1, s->pwr_tcm_a[1]);
    PROPAGATE_FIELD1(s, TCM_PWR_CNTRL, TCMB1,
                     TCM_PWR_STATUS, TCMB1, s->pwr_tcm_b[1]);

    PROPAGATE_GPIO(s, TCM_RET_CNTRL, TCMA0, s->ret_tcm_a[0]);
    PROPAGATE_GPIO(s, TCM_RET_CNTRL, TCMB0, s->ret_tcm_b[0]);
    PROPAGATE_GPIO(s, TCM_RET_CNTRL, TCMA1, s->ret_tcm_a[1]);
    PROPAGATE_GPIO(s, TCM_RET_CNTRL, TCMB1, s->ret_tcm_b[1]);

    PROPAGATE_GPIO(s, RPU_PWR_STATUS, PWR_GATES, s->pwr_rpu);

    /* This is wako but we need it for backwards compatibility.  */
    qemu_set_irq(s->gpi_enable[0], s->regs[R_GPI1_ENABLE]);
    qemu_set_irq(s->gpi_enable[1], s->regs[R_GPI2_ENABLE]);
}

static void prop_power_gate_postw(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);
    uint64_t addr = reg->access->addr;
    uint32_t val32 = val64;
    unsigned int i, n;
    uint32_t src_val;

    for (i = 0; !power_reg_map[i].end; i++) {
        if (addr != power_reg_map[i].addr) {
            continue;
        }
        src_val = val32 & (power_reg_map[i].mask << power_reg_map[i].bit);

        for (n = 0; !power_reg_map[i].map[n].end; n++) {
            uint64_t dst_addr = power_reg_map[i].map[n].addr;
            unsigned int dst_bit = power_reg_map[i].map[n].bit;
            uint32_t dst_mask;
            uint32_t dst_val;

            dst_mask = power_reg_map[i].mask << dst_bit;
            if (power_reg_map[i].map[n].mask) {
                dst_mask = power_reg_map[i].map[n].mask << dst_bit;
            }
            dst_val = src_val ^ power_reg_map[i].map[n].xor;
            dst_val <<= dst_bit;

            s->regs[dst_addr / 4] &= ~dst_mask;
            s->regs[dst_addr / 4] |= dst_val;
        }
    }

    update_gpios(s);
}

static void update_gpios_postw(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);

    update_gpios(s);
}

#define FPD_ISOLATION_MASK \
    ( R_DOMAIN_ISO_CNTRL_LP_FP_1_MASK |	\
      R_DOMAIN_ISO_CNTRL_LP_FP_2_MASK |	\
      R_DOMAIN_ISO_CNTRL_FP_PL_MASK )

/* Used to control FPD power state, depending on the state of the isolation
 * bits.
 * FIXME: At the moment, this looks like the best place from which to control
 * the state of the FPD. If a better location is found, this should be moved.
 */
static void domain_iso_cntrl_postw(RegisterInfo *reg, uint64_t val64)
{
    PMULocal *s = XILINX_PMU_LOCAL(reg->opaque);
    uint32_t val = val64;

    if ((val & FPD_ISOLATION_MASK) == FPD_ISOLATION_MASK) {
        qemu_set_irq(s->fpd_pwr_cntrl, 0);
    } else {
        qemu_set_irq(s->fpd_pwr_cntrl, 1);
    }
}


static const RegisterAccessInfo pmu_local_regs_info[] = {
    {   .name = "ACPU0_PWR_CNTRL",  .addr = A_ACPU0_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU0_PWR_STATUS",  .addr = A_ACPU0_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU1_PWR_CNTRL",  .addr = A_ACPU1_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU1_PWR_STATUS",  .addr = A_ACPU1_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU2_PWR_CNTRL",  .addr = A_ACPU2_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU2_PWR_STATUS",  .addr = A_ACPU2_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "ACPU3_PWR_CNTRL",  .addr = A_ACPU3_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "ACPU3_PWR_STATUS",  .addr = A_ACPU3_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "PP0_PWR_CNTRL",  .addr = A_PP0_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "PP0_PWR_STATUS",  .addr = A_PP0_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "PP1_PWR_CNTRL",  .addr = A_PP1_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "PP1_PWR_STATUS",  .addr = A_PP1_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "USB0_PWR_CNTRL",  .addr = A_USB0_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "USB0_PWR_STATUS",  .addr = A_USB0_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "USB1_PWR_CNTRL",  .addr = A_USB1_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "USB1_PWR_STATUS",  .addr = A_USB1_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "RPU_PWR_CNTRL",  .addr = A_RPU_PWR_CNTRL,
        .reset = 0xf,
        .rsvd = 0xffffffe0,
        .ro = 0xffffffe0,
        .post_write = prop_power_gate_postw,
    },{ .name = "RPU_PWR_STATUS",  .addr = A_RPU_PWR_STATUS,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "L2_PWR_CNTRL",  .addr = A_L2_PWR_CNTRL,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
        .post_write = prop_power_gate_postw,
    },{ .name = "L2_RET_CNTRL",  .addr = A_L2_RET_CNTRL,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
        .post_write = update_gpios_postw,
    },{ .name = "L2_CE_CNTRL",  .addr = A_L2_CE_CNTRL,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "L2_PWR_STATUS",  .addr = A_L2_PWR_STATUS,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xffffffff,
    },{ .name = "OCM_PWR_CNTRL",  .addr = A_OCM_PWR_CNTRL,
        .reset = 0x1010101,
        .rsvd = 0xfefefefe,
        .ro = 0xfefefefe,
        .post_write = update_gpios_postw,
    },{ .name = "OCM_RET_CNTRL",  .addr = A_OCM_RET_CNTRL,
        .rsvd = 0xfffffff0,
        .ro = 0xfffffff0,
        .post_write = update_gpios_postw,
    },{ .name = "OCM_CE_CNTRL",  .addr = A_OCM_CE_CNTRL,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xfffffff0,
    },{ .name = "OCM_PWR_STATUS",  .addr = A_OCM_PWR_STATUS,
        .reset = 0x1010101,
        .rsvd = 0xfefefefe,
        .ro = 0xffffffff,
    },{ .name = "TCM_PWR_CNTRL",  .addr = A_TCM_PWR_CNTRL,
        .reset = 0x1010101,
        .rsvd = 0xfefefefe,
        .ro = 0xfefefefe,
        .post_write = update_gpios_postw,
    },{ .name = "TCM_RET_CNTRL",  .addr = A_TCM_RET_CNTRL,
        .rsvd = 0xfffffff0,
        .ro = 0xfffffff0,
        .post_write = update_gpios_postw,
    },{ .name = "TCM_CE_CNTRL",  .addr = A_TCM_CE_CNTRL,
        .reset = 0xf,
        .rsvd = 0xfffffff0,
        .ro = 0xfffffff0,
    },{ .name = "TCM_PWR_STATUS",  .addr = A_TCM_PWR_STATUS,
        .reset = 0x1010101,
        .rsvd = 0xfefefefe,
        .ro = 0xffffffff,
    },{ .name = "DOMAIN_ISO_CNTRL",  .addr = A_DOMAIN_ISO_CNTRL,
        .reset = 0x28,
        .rsvd = 0x7fffffc0,
        .ro = 0x7fffffc0,
    },{ .name = "LOC_PWR_STATE",  .addr = A_LOC_PWR_STATE,
        .reset = 0x3ffcbf,
        .rsvd = 0xffc00340,
        .ro = 0xffc00340,
    },{ .name = "LOC_AUX_PWR_STATE",  .addr = A_LOC_AUX_PWR_STATE,
        .reset = 0xff080,
        .rsvd = 0x7f00f7f,
        .ro = 0x7f00f00,
    },{ .name = "LOCAL_RESET",  .addr = A_LOCAL_RESET,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
        .post_write = update_gpios_postw,
    },{ .name = "LOCAL_CNTRL",  .addr = A_LOCAL_CNTRL,
        .rsvd = 0xfffffffc,
        .ro = 0xfffffffc,
    },{ .name = "GPO1_READ",  .addr = A_GPO1_READ,
        .rsvd = 0xffffffc0,
        .ro = 0xffffffff,
    },{ .name = "GPO2_READ",  .addr = A_GPO2_READ,
        .rsvd = 0xfffffc3f,
        .ro = 0xffffffff,
    },{ .name = "GPO3_READ",  .addr = A_GPO3_READ,
        .ro = 0xffffffff,
    },{ .name = "GPI1_ENABLE",  .addr = A_GPI1_ENABLE,
        .rsvd = 0xf0e0000,
        .ro = 0xf0e0000,
        .post_write = update_gpios_postw,
    },{ .name = "GPI2_ENABLE",  .addr = A_GPI2_ENABLE,
        .rsvd = 0x1f00fc80,
        .ro = 0x1f00fc80,
        .post_write = update_gpios_postw,
    },{ .name = "GPI3_ENABLE",  .addr = A_GPI3_ENABLE,
    },{ .name = "LOCAL_GEN_STORAGE0",  .addr = A_LOCAL_GEN_STORAGE0,
    },{ .name = "LOCAL_GEN_STORAGE1",  .addr = A_LOCAL_GEN_STORAGE1,
    },{ .name = "LOCAL_GEN_STORAGE2",  .addr = A_LOCAL_GEN_STORAGE2,
    },{ .name = "LOCAL_GEN_STORAGE3",  .addr = A_LOCAL_GEN_STORAGE3,
    },{ .name = "PERS_LOC_GEN_STORAGE0",  .addr = A_PERS_LOC_GEN_STORAGE0,
    },{ .name = "PERS_LOC_GEN_STORAGE1",  .addr = A_PERS_LOC_GEN_STORAGE1,
    },{ .name = "PERS_LOC_GEN_STORAGE2",  .addr = A_PERS_LOC_GEN_STORAGE2,
    },{ .name = "PERS_LOC_GEN_STORAGE3",  .addr = A_PERS_LOC_GEN_STORAGE3,
    },{ .name = "ADDR_ERROR_STATUS",  .addr = A_ADDR_ERROR_STATUS,
        .w1c = 0x1,
        .post_write = addr_error_status_postw,
    },{ .name = "ADDR_ERROR_INT_MASK",  .addr = A_ADDR_ERROR_INT_MASK,
        .reset = 0x1,
        .ro = 0x1,
    },{ .name = "ADDR_ERROR_INT_EN",  .addr = A_ADDR_ERROR_INT_EN,
        .pre_write = addr_error_int_en_prew,
    },{ .name = "ADDR_ERROR_INT_DIS",  .addr = A_ADDR_ERROR_INT_DIS,
        .pre_write = addr_error_int_dis_prew,
    },{ .name = "MBISR_CNTRL",  .addr = A_MBISR_CNTRL,
        .rsvd = 0xffffffde,
        .ro = 0xffffffde,
    },{ .name = "MBISR_STATUS",  .addr = A_MBISR_STATUS,
        .rsvd = 0xffffffee,
        .ro = 0xffffffff,
    },{ .name = "PMU_PB_ERR",  .addr = A_PMU_PB_ERR,
    },{ .name = "PMU_SERV_ERR",  .addr = A_PMU_SERV_ERR,
        .rsvd = 0xf700000,
        .ro = 0xf700000,
    },{ .name = "PWR_ACK_ERR_LPD",  .addr = A_PWR_ACK_ERR_LPD,
    },{ .name = "PWR_ACK_ERR_FPD",  .addr = A_PWR_ACK_ERR_FPD,
    },{ .name = "SERV_LOGCLR_ERR",  .addr = A_SERV_LOGCLR_ERR,
    },{ .name = "LOGCLR_TRIG",  .addr = A_LOGCLR_TRIG,
        .rsvd = 0xfffccb30,
    },{ .name = "LOGCLR_ACK",  .addr = A_LOGCLR_ACK,
        .rsvd = 0xfffccb30,
        .ro = 0xffffffff,
    },{ .name = "APU_WFI_STATUS",  .addr = A_APU_WFI_STATUS,
        .rsvd = 0xfffefff0,
        .ro = 0xffffffff,
    },{ .name = "MBIST_RST",  .addr = A_MBIST_RST,
    },{ .name = "MBIST_PG_EN",  .addr = A_MBIST_PG_EN,
    },{ .name = "MBIST_SETUP",  .addr = A_MBIST_SETUP,
    },{ .name = "MBIST_DONE",  .addr = A_MBIST_DONE,
        .ro = 0x3,
    },{ .name = "MBIST_GOOD",  .addr = A_MBIST_GOOD,
        .ro = 0x3,
    },{ .name = "ECO_1",  .addr = A_ECO_1,
    },{ .name = "ECO_2",  .addr = A_ECO_2,
    }
};

static void pmu_local_reset(DeviceState *dev)
{
    PMULocal *s = XILINX_PMU_LOCAL(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    /*
     * since post_write is not called on dep_register_reset, we have to manually
     * call the post_write function for the DOMAIN_ISO_CNTRL register to
     * ensure that the FPD power state is updated correctly on reset
     */
    domain_iso_cntrl_postw(&s->regs_info[R_DOMAIN_ISO_CNTRL],
                            s->regs[R_DOMAIN_ISO_CNTRL]);

    addr_error_int_update_irq(s);
    update_gpios(s);
}

static const MemoryRegionOps pmu_local_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void pmu_local_realize(DeviceState *dev, Error **errp)
{
    PMULocal *s = XILINX_PMU_LOCAL(dev);

    qdev_init_gpio_out_named(dev, &s->rst_csu, "CSU_RST", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_acpu[0], "ACPU0_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_acpu[1], "ACPU1_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_acpu[2], "ACPU2_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_acpu[3], "ACPU3_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_pp[0], "PP0_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_pp[1], "PP1_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_usb[0], "USB0_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_usb[1], "USB1_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_rpu, "RPU_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_l2, "L2_PWR_CNTRL", 1);
    qdev_init_gpio_out_named(dev, &s->ret_l2, "L2_RET_CNTRL", 1);

    qdev_init_gpio_out_named(dev, &s->pwr_ocm[0], "OCM_PWR_CNTRL_BANK0", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_ocm[1], "OCM_PWR_CNTRL_BANK1", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_ocm[2], "OCM_PWR_CNTRL_BANK2", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_ocm[3], "OCM_PWR_CNTRL_BANK3", 1);

    qdev_init_gpio_out_named(dev, &s->ret_ocm[0], "OCM_RET_CNTRL_BANK0", 1);
    qdev_init_gpio_out_named(dev, &s->ret_ocm[1], "OCM_RET_CNTRL_BANK1", 1);
    qdev_init_gpio_out_named(dev, &s->ret_ocm[2], "OCM_RET_CNTRL_BANK2", 1);
    qdev_init_gpio_out_named(dev, &s->ret_ocm[3], "OCM_RET_CNTRL_BANK3", 1);

    qdev_init_gpio_out_named(dev, &s->pwr_tcm_a[0], "TCM_PWR_CNTRL_A0", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_tcm_b[0], "TCM_PWR_CNTRL_B0", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_tcm_a[1], "TCM_PWR_CNTRL_A1", 1);
    qdev_init_gpio_out_named(dev, &s->pwr_tcm_b[1], "TCM_PWR_CNTRL_B1", 1);

    qdev_init_gpio_out_named(dev, &s->ret_tcm_a[0], "TCM_RET_CNTRL_A0", 1);
    qdev_init_gpio_out_named(dev, &s->ret_tcm_b[0], "TCM_RET_CNTRL_B0", 1);
    qdev_init_gpio_out_named(dev, &s->ret_tcm_a[1], "TCM_RET_CNTRL_A1", 1);
    qdev_init_gpio_out_named(dev, &s->ret_tcm_b[1], "TCM_RET_CNTRL_B1", 1);

    qdev_init_gpio_out_named(dev, &s->fpd_pwr_cntrl, "fpd_pwr_cntrl", 1);

    qdev_init_gpio_out_named(dev, &s->gpi_enable[0], "GPI1_ENABLE", 1);
    qdev_init_gpio_out_named(dev, &s->gpi_enable[1], "GPI2_ENABLE", 1);
}

static void pmu_local_init(Object *obj)
{
    PMULocal *s = XILINX_PMU_LOCAL(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_PMU_LOCAL,
                       PMU_LOCAL_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), pmu_local_regs_info,
                              ARRAY_SIZE(pmu_local_regs_info),
                              s->regs_info, s->regs,
                              &pmu_local_ops,
                              XILINX_PMU_LOCAL_ERR_DEBUG,
                              PMU_LOCAL_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_addr_error_int);
}

static const VMStateDescription vmstate_pmu_local = {
    .name = TYPE_XILINX_PMU_LOCAL,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, PMULocal, PMU_LOCAL_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet pmu_local_controller_gpios[] = {
    {
       .names = &fdt_generic_gpio_name_set_gpio,
       .gpios = (FDTGenericGPIOConnection []) {
            { .name = "CSU_RST",   .fdt_index = 0 },
            { .name = "ACPU0_PWR_CNTRL",   .fdt_index = 1 },
            { .name = "ACPU1_PWR_CNTRL",   .fdt_index = 2 },
            { .name = "ACPU2_PWR_CNTRL",   .fdt_index = 3 },
            { .name = "ACPU3_PWR_CNTRL",   .fdt_index = 4 },
            { .name = "PP0_PWR_CNTRL",     .fdt_index = 5 },
            { .name = "PP1_PWR_CNTRL",     .fdt_index = 6 },
            { .name = "USB0_PWR_CNTRL",    .fdt_index = 7 },
            { .name = "USB1_PWR_CNTRL",    .fdt_index = 8 },
            { .name = "RPU_PWR_CNTRL",     .fdt_index = 9 },
            { .name = "L2_PWR_CNTRL",      .fdt_index = 10 },
            { .name = "L2_RET_CNTRL",      .fdt_index = 11 },
            { .name = "OCM_PWR_CNTRL_BANK0",    .fdt_index = 12 },
            { .name = "OCM_PWR_CNTRL_BANK1",    .fdt_index = 13 },
            { .name = "OCM_PWR_CNTRL_BANK2",    .fdt_index = 14 },
            { .name = "OCM_PWR_CNTRL_BANK3",    .fdt_index = 15 },
            { .name = "OCM_RET_CNTRL_BANK0",    .fdt_index = 16 },
            { .name = "OCM_RET_CNTRL_BANK1",    .fdt_index = 17 },
            { .name = "OCM_RET_CNTRL_BANK2",    .fdt_index = 18 },
            { .name = "OCM_RET_CNTRL_BANK3",    .fdt_index = 19 },
            { .name = "TCM_PWR_CNTRL_A0",     .fdt_index = 20 },
            { .name = "TCM_PWR_CNTRL_B0",     .fdt_index = 21 },
            { .name = "TCM_PWR_CNTRL_A1",     .fdt_index = 22 },
            { .name = "TCM_PWR_CNTRL_B1",     .fdt_index = 23 },
            { .name = "TCM_RET_CNTRL_A0",     .fdt_index = 24 },
            { .name = "TCM_RET_CNTRL_B0",     .fdt_index = 25 },
            { .name = "TCM_RET_CNTRL_A1",     .fdt_index = 26 },
            { .name = "TCM_RET_CNTRL_B1",     .fdt_index = 27 },
            { .name = "fpd_pwr_cntrl",          .fdt_index = 28},
            { .name = "GPI1_ENABLE",            .fdt_index = 29},
            { .name = "GPI2_ENABLE",            .fdt_index = 30},
            { },
       },
    },
    { },
};

static void pmu_local_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = pmu_local_reset;
    dc->realize = pmu_local_realize;
    dc->vmsd = &vmstate_pmu_local;
    fggc->controller_gpios = pmu_local_controller_gpios;
}

static const TypeInfo pmu_local_info = {
    .name          = TYPE_XILINX_PMU_LOCAL,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(PMULocal),
    .class_init    = pmu_local_class_init,
    .instance_init = pmu_local_init,
    .interfaces    = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void pmu_local_register_types(void)
{
    type_register_static(&pmu_local_info);
}

type_init(pmu_local_register_types)
