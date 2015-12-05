/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <io.h>
#include <soc/intc.h>
#include <soc/tcu.h>



static inline void dump_regs_soc(void)
{
	diag_puts("-- SOC --\n");
	dump_cp0(c0_config7);
	dump_cp0(c0_core_ctrl);
	dump_cp0(c0_core_stat);
	dump_cp0(c0_core_reim);
	dump_cp0(c0_mailbox0);
	dump_cp0(c0_mailbox1);

	dump_mmio(INTC_BASE, INTC_ICSR(0));
	dump_mmio(INTC_BASE, INTC_ICSR(1));
	dump_mmio(INTC_BASE, INTC_ICMR(0));
	dump_mmio(INTC_BASE, INTC_ICMR(1));
	dump_mmio(INTC_BASE, INTC_ICPR(0));
	dump_mmio(INTC_BASE, INTC_ICPR(1));

	dump_mmio(TCU_BASE, TCU_TSTR);
	dump_mmio(TCU_BASE, TCU_TSR);
	dump_mmio(TCU_BASE, TCU_TER);
	dump_mmio(TCU_BASE, TCU_TFR);
	dump_mmio(TCU_BASE, TCU_TMR);
	dump_mmio(TCU_BASE, OST_CMP);
	dump_mmio(TCU_BASE, OST_CNTL);
	dump_mmio(TCU_BASE, TCU_TDFR(0));
	dump_mmio(TCU_BASE, TCU_TCNT(0));
}
