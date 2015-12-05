/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <io.h>
#include <arch/memory.h>
#include <soc/baseaddr.h>
#include <soc/gpio.h>

#define	IOBASE		(KSEG1_BASE + GPIO_BASE)
#define	GPIO_LED	(1 << 15)

static inline void led_init(void)
{
	iowrite32(IOBASE + GPIO_INTC(5), GPIO_LED);
	iowrite32(IOBASE + GPIO_MSKS(5), GPIO_LED);
	iowrite32(IOBASE + GPIO_PAT1C(5),GPIO_LED);
}

static inline void led(int state)
{
	if (state)
		iowrite32(IOBASE + GPIO_PAT0S(5), GPIO_LED);
	else
		iowrite32(IOBASE + GPIO_PAT0C(5), GPIO_LED);
}
