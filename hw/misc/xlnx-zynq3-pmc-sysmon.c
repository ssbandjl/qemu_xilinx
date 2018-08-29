/*
 * QEMU model of the SYSMON System Monitor
 *
 * Copyright (c) 2018 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2018-08-29.
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

#ifndef PMC_SYSMON_ERR_DEBUG
#define PMC_SYSMON_ERR_DEBUG 0
#endif

#define TYPE_PMC_SYSMON "xlnx.pmc-sysmon"

#define PMC_SYSMON(obj) \
     OBJECT_CHECK(PMCSysMon, (obj), TYPE_PMC_SYSMON)

REG32(REG_PCSR_MASK, 0x0)
    FIELD(REG_PCSR_MASK, PWRDN, 14, 1)
    FIELD(REG_PCSR_MASK, DISNPICLK, 13, 1)
    FIELD(REG_PCSR_MASK, APBEN, 12, 1)
    FIELD(REG_PCSR_MASK, SCANCLR, 11, 1)
    FIELD(REG_PCSR_MASK, STARTCAL, 10, 1)
    FIELD(REG_PCSR_MASK, FABRICEN, 9, 1)
    FIELD(REG_PCSR_MASK, TRISTATE, 8, 1)
    FIELD(REG_PCSR_MASK, HOLDSTATE, 7, 1)
    FIELD(REG_PCSR_MASK, INITSTATE, 6, 1)
    FIELD(REG_PCSR_MASK, ODISABLE, 2, 4)
    FIELD(REG_PCSR_MASK, GATEREG, 1, 1)
    FIELD(REG_PCSR_MASK, PCOMPLETE, 0, 1)
REG32(REG_PCSR_CONTROL, 0x4)
    FIELD(REG_PCSR_CONTROL, PWRDN, 14, 1)
    FIELD(REG_PCSR_CONTROL, DISNPICLK, 13, 1)
    FIELD(REG_PCSR_CONTROL, APBEN, 12, 1)
    FIELD(REG_PCSR_CONTROL, SCANCLR, 11, 1)
    FIELD(REG_PCSR_CONTROL, STARTCAL, 10, 1)
    FIELD(REG_PCSR_CONTROL, FABRICEN, 9, 1)
    FIELD(REG_PCSR_CONTROL, TRISTATE, 8, 1)
    FIELD(REG_PCSR_CONTROL, HOLDSTATE, 7, 1)
    FIELD(REG_PCSR_CONTROL, INITSTATE, 6, 1)
    FIELD(REG_PCSR_CONTROL, ODISABLE, 2, 4)
    FIELD(REG_PCSR_CONTROL, GATEREG, 1, 1)
    FIELD(REG_PCSR_CONTROL, PCOMPLETE, 0, 1)
REG32(REG_PCSR_STATUS, 0x8)
    FIELD(REG_PCSR_STATUS, APB3MOD, 5, 1)
    FIELD(REG_PCSR_STATUS, CALERROR, 4, 1)
    FIELD(REG_PCSR_STATUS, CALDONE, 3, 1)
    FIELD(REG_PCSR_STATUS, INCAL, 2, 1)
    FIELD(REG_PCSR_STATUS, SCANERR, 1, 1)
    FIELD(REG_PCSR_STATUS, SCANDONE, 0, 1)
REG32(SYSMON_ALARM_ISR, 0x10)
    FIELD(SYSMON_ALARM_ISR, ALARM7, 7, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM6, 6, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM5, 5, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM4, 4, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM3, 3, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM2, 2, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM1, 1, 1)
    FIELD(SYSMON_ALARM_ISR, ALARM0, 0, 1)
REG32(SYSMON_ALARM_IMR, 0x14)
    FIELD(SYSMON_ALARM_IMR, ALARM7, 7, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM6, 6, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM5, 5, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM4, 4, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM3, 3, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM2, 2, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM1, 1, 1)
    FIELD(SYSMON_ALARM_IMR, ALARM0, 0, 1)
REG32(SYSMON_ALARM_IEN, 0x18)
    FIELD(SYSMON_ALARM_IEN, ALARM7, 7, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM6, 6, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM5, 5, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM4, 4, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM3, 3, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM2, 2, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM1, 1, 1)
    FIELD(SYSMON_ALARM_IEN, ALARM0, 0, 1)
REG32(SYSMON_ALARM_IDS, 0x1c)
    FIELD(SYSMON_ALARM_IDS, ALARM7, 7, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM6, 6, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM5, 5, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM4, 4, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM3, 3, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM2, 2, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM1, 1, 1)
    FIELD(SYSMON_ALARM_IDS, ALARM0, 0, 1)
REG32(SYSMON_OT_ISR, 0x20)
    FIELD(SYSMON_OT_ISR, OT, 0, 1)
REG32(SYSMON_OT_IMR, 0x24)
    FIELD(SYSMON_OT_IMR, OT, 0, 1)
REG32(SYSMON_OT_IEN, 0x28)
    FIELD(SYSMON_OT_IEN, OT, 0, 1)
REG32(SYSMON_OT_IDS, 0x2c)
    FIELD(SYSMON_OT_IDS, OT, 0, 1)
REG32(TEMPERATURE, 0x100)
    FIELD(TEMPERATURE, VAL, 0, 16)
REG32(SUPPLY0, 0x104)
    FIELD(SUPPLY0, VAL, 0, 16)
REG32(SUPPLY1, 0x108)
    FIELD(SUPPLY1, VAL, 0, 16)
REG32(SUPPLY2, 0x10c)
    FIELD(SUPPLY2, VAL, 0, 16)
REG32(SUPPLY3, 0x110)
    FIELD(SUPPLY3, VAL, 0, 16)
REG32(SUPPLY4, 0x114)
    FIELD(SUPPLY4, VAL, 0, 16)
REG32(SUPPLY5, 0x118)
    FIELD(SUPPLY5, VAL, 0, 16)
REG32(SUPPLY6, 0x11c)
    FIELD(SUPPLY6, VAL, 0, 16)
REG32(TEMPERATURE_MAX, 0x200)
    FIELD(TEMPERATURE_MAX, VAL, 0, 16)
REG32(SUPPLY0_MAX, 0x204)
    FIELD(SUPPLY0_MAX, VAL, 0, 16)
REG32(SUPPLY1_MAX, 0x208)
    FIELD(SUPPLY1_MAX, VAL, 0, 16)
REG32(SUPPLY2_MAX, 0x20c)
    FIELD(SUPPLY2_MAX, VAL, 0, 16)
REG32(SUPPLY3_MAX, 0x210)
    FIELD(SUPPLY3_MAX, VAL, 0, 16)
REG32(SUPPLY4_MAX, 0x214)
    FIELD(SUPPLY4_MAX, VAL, 0, 16)
REG32(SUPPLY5_MAX, 0x218)
    FIELD(SUPPLY5_MAX, VAL, 0, 16)
REG32(SUPPLY6_MAX, 0x21c)
    FIELD(SUPPLY6_MAX, VAL, 0, 16)
REG32(TEMPERATURE_MIN, 0x220)
    FIELD(TEMPERATURE_MIN, VAL, 0, 16)
REG32(SUPPLY0_MIN, 0x224)
    FIELD(SUPPLY0_MIN, VAL, 0, 16)
REG32(SUPPLY1_MIN, 0x228)
    FIELD(SUPPLY1_MIN, VAL, 0, 16)
REG32(SUPPLY2_MIN, 0x22c)
    FIELD(SUPPLY2_MIN, VAL, 0, 16)
REG32(SUPPLY3_MIN, 0x230)
    FIELD(SUPPLY3_MIN, VAL, 0, 16)
REG32(SUPPLY4_MIN, 0x234)
    FIELD(SUPPLY4_MIN, VAL, 0, 16)
REG32(SUPPLY5_MIN, 0x238)
    FIELD(SUPPLY5_MIN, VAL, 0, 16)
REG32(SUPPLY6_MIN, 0x23c)
    FIELD(SUPPLY6_MIN, VAL, 0, 16)
REG32(CAL_0, 0x240)
    FIELD(CAL_0, VAL, 0, 16)
REG32(CAL_1, 0x244)
    FIELD(CAL_1, VAL, 0, 16)
REG32(CAL_2, 0x248)
    FIELD(CAL_2, VAL, 0, 16)
REG32(CAL_3, 0x24c)
    FIELD(CAL_3, VAL, 0, 16)
REG32(CAL_4, 0x250)
    FIELD(CAL_4, VAL, 0, 16)
REG32(CAL_5, 0x254)
    FIELD(CAL_5, VAL, 0, 16)
REG32(CAL_6, 0x258)
    FIELD(CAL_6, VAL, 0, 16)
REG32(CAL_7, 0x25c)
    FIELD(CAL_7, VAL, 0, 16)
REG32(CAL_8, 0x260)
    FIELD(CAL_8, VAL, 0, 16)
REG32(CAL_9, 0x264)
    FIELD(CAL_9, VAL, 0, 16)
REG32(CONFIG0, 0x300)
REG32(CONFIG1, 0x304)
REG32(CONFIG2, 0x308)
REG32(CONFIG3, 0x30c)
REG32(SEQUENCE_CHANNEL, 0x310)
REG32(SEQUENCE_ORDER0, 0x314)
REG32(SEQUENCE_ORDER1, 0x318)
REG32(SEQUENCE_ORDER2, 0x31c)
REG32(SEQUENCE_ORDER3, 0x320)
REG32(SEQUENCE_ORDER4, 0x324)
REG32(SEQUENCE_ORDER5, 0x328)
REG32(SEQUENCE_AVERAGE, 0x32c)
REG32(SEQUENCE_INPUT_MODE, 0x330)
REG32(SEQUENCE_ACQUISITION, 0x334)
REG32(TEMPERATURE_TH_UPPER, 0x338)
    FIELD(TEMPERATURE_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY0_TH_UPPER, 0x33c)
    FIELD(SUPPLY0_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY1_TH_UPPER, 0x340)
    FIELD(SUPPLY1_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY2_TH_UPPER, 0x344)
    FIELD(SUPPLY2_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY3_TH_UPPER, 0x348)
    FIELD(SUPPLY3_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY4_TH_UPPER, 0x34c)
    FIELD(SUPPLY4_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY5_TH_UPPER, 0x350)
    FIELD(SUPPLY5_TH_UPPER, VAL, 0, 16)
REG32(SUPPLY6_TH_UPPER, 0x354)
    FIELD(SUPPLY6_TH_UPPER, VAL, 0, 16)
REG32(TEMPERATURE_TH_LOWER, 0x358)
    FIELD(TEMPERATURE_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY0_TH_LOWER, 0x35c)
    FIELD(SUPPLY0_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY1_TH_LOWER, 0x360)
    FIELD(SUPPLY1_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY2_TH_LOWER, 0x364)
    FIELD(SUPPLY2_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY3_TH_LOWER, 0x368)
    FIELD(SUPPLY3_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY4_TH_LOWER, 0x36c)
    FIELD(SUPPLY4_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY5_TH_LOWER, 0x370)
    FIELD(SUPPLY5_TH_LOWER, VAL, 0, 16)
REG32(SUPPLY6_TH_LOWER, 0x374)
    FIELD(SUPPLY6_TH_LOWER, VAL, 0, 16)
REG32(ABUS_SWITCH01, 0x378)
REG32(ABUS_SWITCH23, 0x37c)
REG32(ABUS_SWITCH45, 0x380)
REG32(ABUS_SWITCH67, 0x384)
REG32(ABUS_SWITCH89, 0x388)
REG32(ABUS_SWITCH1011, 0x38c)
REG32(ABUS_SWITCH1213, 0x390)
REG32(ABUS_SWITCH1415, 0x394)

#define SYSMON_R_MAX (R_ABUS_SWITCH1415 + 1)

typedef struct PMCSysMon {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_sysmon_alarm_imr;
    qemu_irq irq_sysmon_ot_imr;

    uint32_t regs[SYSMON_R_MAX];
    RegisterInfo regs_info[SYSMON_R_MAX];
} PMCSysMon;

static void sysmon_alarm_imr_update_irq(PMCSysMon *s)
{
    bool pending = s->regs[R_SYSMON_ALARM_ISR] & ~s->regs[R_SYSMON_ALARM_IMR];
    qemu_set_irq(s->irq_sysmon_alarm_imr, pending);
}

static void sysmon_alarm_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    sysmon_alarm_imr_update_irq(s);
}

static uint64_t sysmon_alarm_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SYSMON_ALARM_IMR] &= ~val;
    sysmon_alarm_imr_update_irq(s);
    return 0;
}

static uint64_t sysmon_alarm_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SYSMON_ALARM_IMR] |= val;
    sysmon_alarm_imr_update_irq(s);
    return 0;
}

static void sysmon_ot_imr_update_irq(PMCSysMon *s)
{
    bool pending = s->regs[R_SYSMON_OT_ISR] & ~s->regs[R_SYSMON_OT_IMR];
    qemu_set_irq(s->irq_sysmon_ot_imr, pending);
}

static void sysmon_ot_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    sysmon_ot_imr_update_irq(s);
}

static uint64_t sysmon_ot_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SYSMON_OT_IMR] &= ~val;
    sysmon_ot_imr_update_irq(s);
    return 0;
}

static uint64_t sysmon_ot_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    PMCSysMon *s = PMC_SYSMON(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SYSMON_OT_IMR] |= val;
    sysmon_ot_imr_update_irq(s);
    return 0;
}

static const RegisterAccessInfo sysmon_regs_info[] = {
    {   .name = "REG_PCSR_MASK",  .addr = A_REG_PCSR_MASK,
        .rsvd = 0xffff8000,
    },{ .name = "REG_PCSR_CONTROL",  .addr = A_REG_PCSR_CONTROL,
        .reset = 0x1fe,
        .rsvd = 0xffff8000,
    },{ .name = "REG_PCSR_STATUS",  .addr = A_REG_PCSR_STATUS,
        .reset = R_REG_PCSR_STATUS_SCANDONE_MASK \
                 | R_REG_PCSR_STATUS_CALDONE_MASK,
        .rsvd = 0xffffffc0,
        .ro = 0x3f,
    },{ .name = "SYSMON_ALARM_ISR",  .addr = A_SYSMON_ALARM_ISR,
        .rsvd = 0xffffff00,
        .w1c = 0xff,
        .post_write = sysmon_alarm_isr_postw,
    },{ .name = "SYSMON_ALARM_IMR",  .addr = A_SYSMON_ALARM_IMR,
        .rsvd = 0xffffff00,
        .w1c = 0xff,
    },{ .name = "SYSMON_ALARM_IEN",  .addr = A_SYSMON_ALARM_IEN,
        .rsvd = 0xffffff00,
        .w1c = 0xff,
        .pre_write = sysmon_alarm_ien_prew,
    },{ .name = "SYSMON_ALARM_IDS",  .addr = A_SYSMON_ALARM_IDS,
        .rsvd = 0xffffff00,
        .w1c = 0xff,
        .pre_write = sysmon_alarm_ids_prew,
    },{ .name = "SYSMON_OT_ISR",  .addr = A_SYSMON_OT_ISR,
        .rsvd = 0xfffffffe,
        .w1c = 0x1,
        .post_write = sysmon_ot_isr_postw,
    },{ .name = "SYSMON_OT_IMR",  .addr = A_SYSMON_OT_IMR,
        .rsvd = 0xfffffffe,
        .w1c = 0x1,
    },{ .name = "SYSMON_OT_IEN",  .addr = A_SYSMON_OT_IEN,
        .rsvd = 0xfffffffe,
        .w1c = 0x1,
        .pre_write = sysmon_ot_ien_prew,
    },{ .name = "SYSMON_OT_IDS",  .addr = A_SYSMON_OT_IDS,
        .rsvd = 0xfffffffe,
        .w1c = 0x1,
        .pre_write = sysmon_ot_ids_prew,
    },{ .name = "TEMPERATURE",  .addr = A_TEMPERATURE,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY0",  .addr = A_SUPPLY0,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY1",  .addr = A_SUPPLY1,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY2",  .addr = A_SUPPLY2,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY3",  .addr = A_SUPPLY3,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY4",  .addr = A_SUPPLY4,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY5",  .addr = A_SUPPLY5,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY6",  .addr = A_SUPPLY6,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "TEMPERATURE_MAX",  .addr = A_TEMPERATURE_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY0_MAX",  .addr = A_SUPPLY0_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY1_MAX",  .addr = A_SUPPLY1_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY2_MAX",  .addr = A_SUPPLY2_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY3_MAX",  .addr = A_SUPPLY3_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY4_MAX",  .addr = A_SUPPLY4_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY5_MAX",  .addr = A_SUPPLY5_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY6_MAX",  .addr = A_SUPPLY6_MAX,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "TEMPERATURE_MIN",  .addr = A_TEMPERATURE_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY0_MIN",  .addr = A_SUPPLY0_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY1_MIN",  .addr = A_SUPPLY1_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY2_MIN",  .addr = A_SUPPLY2_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY3_MIN",  .addr = A_SUPPLY3_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY4_MIN",  .addr = A_SUPPLY4_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY5_MIN",  .addr = A_SUPPLY5_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "SUPPLY6_MIN",  .addr = A_SUPPLY6_MIN,
        .reset = 0xffff,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_0",  .addr = A_CAL_0,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_1",  .addr = A_CAL_1,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_2",  .addr = A_CAL_2,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_3",  .addr = A_CAL_3,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_4",  .addr = A_CAL_4,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_5",  .addr = A_CAL_5,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_6",  .addr = A_CAL_6,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_7",  .addr = A_CAL_7,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_8",  .addr = A_CAL_8,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CAL_9",  .addr = A_CAL_9,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "CONFIG0",  .addr = A_CONFIG0,
    },{ .name = "CONFIG1",  .addr = A_CONFIG1,
    },{ .name = "CONFIG2",  .addr = A_CONFIG2,
    },{ .name = "CONFIG3",  .addr = A_CONFIG3,
    },{ .name = "SEQUENCE_CHANNEL",  .addr = A_SEQUENCE_CHANNEL,
    },{ .name = "SEQUENCE_ORDER0",  .addr = A_SEQUENCE_ORDER0,
    },{ .name = "SEQUENCE_ORDER1",  .addr = A_SEQUENCE_ORDER1,
    },{ .name = "SEQUENCE_ORDER2",  .addr = A_SEQUENCE_ORDER2,
    },{ .name = "SEQUENCE_ORDER3",  .addr = A_SEQUENCE_ORDER3,
    },{ .name = "SEQUENCE_ORDER4",  .addr = A_SEQUENCE_ORDER4,
    },{ .name = "SEQUENCE_ORDER5",  .addr = A_SEQUENCE_ORDER5,
    },{ .name = "SEQUENCE_AVERAGE",  .addr = A_SEQUENCE_AVERAGE,
    },{ .name = "SEQUENCE_INPUT_MODE",  .addr = A_SEQUENCE_INPUT_MODE,
    },{ .name = "SEQUENCE_ACQUISITION",  .addr = A_SEQUENCE_ACQUISITION,
    },{ .name = "TEMPERATURE_TH_UPPER",  .addr = A_TEMPERATURE_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY0_TH_UPPER",  .addr = A_SUPPLY0_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY1_TH_UPPER",  .addr = A_SUPPLY1_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY2_TH_UPPER",  .addr = A_SUPPLY2_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY3_TH_UPPER",  .addr = A_SUPPLY3_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY4_TH_UPPER",  .addr = A_SUPPLY4_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY5_TH_UPPER",  .addr = A_SUPPLY5_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY6_TH_UPPER",  .addr = A_SUPPLY6_TH_UPPER,
        .rsvd = 0xffff0000,
    },{ .name = "TEMPERATURE_TH_LOWER",  .addr = A_TEMPERATURE_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY0_TH_LOWER",  .addr = A_SUPPLY0_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY1_TH_LOWER",  .addr = A_SUPPLY1_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY2_TH_LOWER",  .addr = A_SUPPLY2_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY3_TH_LOWER",  .addr = A_SUPPLY3_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY4_TH_LOWER",  .addr = A_SUPPLY4_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY5_TH_LOWER",  .addr = A_SUPPLY5_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "SUPPLY6_TH_LOWER",  .addr = A_SUPPLY6_TH_LOWER,
        .rsvd = 0xffff0000,
    },{ .name = "ABUS_SWITCH01",  .addr = A_ABUS_SWITCH01,
    },{ .name = "ABUS_SWITCH23",  .addr = A_ABUS_SWITCH23,
    },{ .name = "ABUS_SWITCH45",  .addr = A_ABUS_SWITCH45,
    },{ .name = "ABUS_SWITCH67",  .addr = A_ABUS_SWITCH67,
    },{ .name = "ABUS_SWITCH89",  .addr = A_ABUS_SWITCH89,
    },{ .name = "ABUS_SWITCH1011",  .addr = A_ABUS_SWITCH1011,
    },{ .name = "ABUS_SWITCH1213",  .addr = A_ABUS_SWITCH1213,
    },{ .name = "ABUS_SWITCH1415",  .addr = A_ABUS_SWITCH1415,
    }
};

static void sysmon_reset(DeviceState *dev)
{
    PMCSysMon *s = PMC_SYSMON(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    sysmon_alarm_imr_update_irq(s);
    sysmon_ot_imr_update_irq(s);
}

static const MemoryRegionOps sysmon_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void sysmon_realize(DeviceState *dev, Error **errp)
{
    /* Delete this if you don't need it */
}

static void sysmon_init(Object *obj)
{
    PMCSysMon *s = PMC_SYSMON(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_PMC_SYSMON, SYSMON_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), sysmon_regs_info,
                              ARRAY_SIZE(sysmon_regs_info),
                              s->regs_info, s->regs,
                              &sysmon_ops,
                              PMC_SYSMON_ERR_DEBUG,
                              SYSMON_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_sysmon_alarm_imr);
    sysbus_init_irq(sbd, &s->irq_sysmon_ot_imr);
}

static const VMStateDescription vmstate_sysmon = {
    .name = TYPE_PMC_SYSMON,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, PMCSysMon, SYSMON_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void sysmon_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = sysmon_reset;
    dc->realize = sysmon_realize;
    dc->vmsd = &vmstate_sysmon;
}

static const TypeInfo sysmon_info = {
    .name          = TYPE_PMC_SYSMON,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(PMCSysMon),
    .class_init    = sysmon_class_init,
    .instance_init = sysmon_init,
};

static void sysmon_register_types(void)
{
    type_register_static(&sysmon_info);
}

type_init(sysmon_register_types)
