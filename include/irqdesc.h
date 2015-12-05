/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_IRQDESC_H_
#define	_IRQDESC_H_


struct irqaction;
struct irqchip;

struct irqdesc {
	void			(*handler)(struct irqdesc *desc);
	struct irqaction*	action;
	struct irqchip*		chip;
	unsigned int		irq;		// relative to the chip
};

struct irqdesc *irq_get_desc(struct irqchip *chip, unsigned int irq);


void irq_handle_desc(struct irqdesc *desc);

#endif
