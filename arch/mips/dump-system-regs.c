/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <arch/regs-copro.h>
#include <soc/regs-copro.h>
#include <arch/memory.h>
#include <debug.h>
#include <diag.h>
#include <io.h>


#define	dump_reg(INS, NAME, ARG)				\
	do {	unsigned long r;				\
		asm volatile(INS "\t%0," ARG : "=r" (r));	\
		diag_puts(NAME);				\
		diag_puts(":\t");				\
		diag_hexval(r);					\
		diag_putc('\n');				\
	} while (0)

#define	dump_cp0(REG)		dump_reg("mfc0", #REG, REG)

#define	dump_mmio(BASE, OFF)					\
	do {							\
		unsigned long r;				\
		r = ioread32(KSEG1_BASE + BASE + OFF);		\
		diag_puts(#OFF);				\
		diag_puts(":\t");				\
		diag_hexval(r);					\
		diag_putc('\n');				\
	} while (0)


#include <soc/dump-regs.h>

void dump_system_regs(void)
{
	diag_putc('\n');
	dump_cp0(c0_status);
	dump_cp0(c0_cause);
	dump_cp0(c0_intctl);
	dump_cp0(c0_hwrena);
	dump_cp0(c0_count);
	dump_cp0(c0_prid);
	dump_cp0(c0_ebase);
	dump_cp0(c0_config);
	dump_cp0(c0_config1);
	dump_cp0(c0_config2);
	dump_cp0(c0_config3);

	dump_regs_soc();
}
