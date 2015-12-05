/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_INTERRUPT_H_
#define	_ARCH_INTERRUPT_H_

struct eframe;

void mach_irq_handler(struct eframe *regs, uint cause, uint status);

#endif
