/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_IRQ_H_
#define	_ARCH_IRQ_H_

#include <irqchip.h>

#define	NR_IRQS	256


extern struct irqchip irqchip_mips;
extern struct irqchip irqchip_intc;

#endif
