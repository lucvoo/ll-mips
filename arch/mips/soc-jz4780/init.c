/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <soc/baseaddr.h>
#include <arch/memory.h>
#include <soc/gpio.h>
#include <init.h>
#include <io.h>


void soc_init(void)
{
	diag_puts("JZ4780 booting ...\n");

#ifdef	CONFIG_JTAG_ENABLE
	// Enable JTAG/Disable UART3
	iowrite32(KSEG1_BASE + GPIO_BASE + GPIO_INTC(0),  3 << 30);
	iowrite32(KSEG1_BASE + GPIO_BASE + GPIO_MSKC(0),  3 << 30);
	iowrite32(KSEG1_BASE + GPIO_BASE + GPIO_PAT1C(0), 3 << 30);
	iowrite32(KSEG1_BASE + GPIO_BASE + GPIO_PAT0C(0), 3 << 30);
#endif
}
