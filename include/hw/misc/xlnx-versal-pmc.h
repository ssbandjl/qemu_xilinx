/*
 * QEMU model of the PMC_GLOBAL This is the database for the
 * PMC Global Register Definitions.
 *
 * Copyright (c) 2017 Xilinx Inc.
 *
 * Partially autogenerated by xregqemu.py 2017-03-28.
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


#define PPU1_UPDATE_CTRL(G)                                                    \
static void ppu1_update_ctrl(G * s)                                            \
{                                                                              \
    unsigned int rst_mode;                                                     \
    bool wakeup;                                                               \
    bool rst;                                                                  \
                                                                               \
    wakeup = ARRAY_FIELD_EX32(s->regs, PPU_1_RST_MODE, WAKEUP);                \
    rst_mode = ARRAY_FIELD_EX32(s->regs, PPU_1_RST_MODE, RST_MODE);            \
    rst = !ARRAY_FIELD_EX32(s->regs, PPU_1_RST, RST_N);                        \
                                                                               \
                                                                               \
    switch (rst_mode) {                                                        \
    case 0:                                                                    \
        /*                                                                     \
         * MB starts executing when released from RESET.                       \
         */                                                                    \
        qemu_set_irq(s->ppu1_rst, rst);                                        \
        break;                                                                 \
    case 1:                                                                    \
        /*                                                                     \
         * MB enters sleep when released from RESET.                           \
         * RST signal can be low only after wakeup is high,                    \
         * wakeup=0 should not effect the RST signal when RST=0                \
         */                                                                    \
        if (wakeup || rst) {                                                   \
            qemu_set_irq(s->ppu1_rst, rst);                                    \
        }                                                                      \
        /*                                                                     \
         * Wakeup (i.e halt) signal is updated only when RST=1                 \
         * So that clearing wakeup bit dosent effect RST signal                \
         */                                                                    \
        qemu_set_irq(s->ppu1_wakeup, rst & wakeup);                            \
        if (!rst) {                                                            \
            ARRAY_FIELD_DP32(s->regs,GLOBAL_CNTRL, MB_SLEEP, !wakeup);         \
        } else {                                                               \
            ARRAY_FIELD_DP32(s->regs,GLOBAL_CNTRL, MB_SLEEP, 0);               \
        }                                                                      \
        break;                                                                 \
    default:                                                                   \
        qemu_log_mask(LOG_GUEST_ERROR, "Invalid PPU1_RST_MODE %x\n", rst_mode);\
        break;                                                                 \
    };                                                                         \
}


