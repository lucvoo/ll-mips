/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <soc/baseaddr.h>
#include <arch/io.h>
#include <16550.h>
#include <diag.h>
#include <init.h>


#define	UART_BASE	(0xa0000000 + (UART4_BASE))
#define	UART_OFF(X)	((X) * 4)

#define OFF_THR		UART_OFF(UART_THR)
#define OFF_LCR		UART_OFF(UART_LCR)
#define OFF_LSR		UART_OFF(UART_LSR)


static void __diag_putc(unsigned char c)
{
	volatile void *base = (volatile void*) UART_BASE;
	int timeout = 8192;

	if (!ioread8(base + OFF_LCR))
		return;

	while (1) {
		uint status = ioread8(base + OFF_LSR);

		if ((status & UART_LSR_THRE) == UART_LSR_THRE)
			break;
		if (--timeout == 0)
			return;
	}

	iowrite8(base + OFF_THR, c);
}


void diag_putc(unsigned int c)
{
	if (c == '\n')
		__diag_putc('\r');
	__diag_putc(c);
}
