/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_IRQ_H_
#define	_IRQ_H_

#include <irqdesc.h>
#include <irqchip.h>


static inline void irq_ack(struct irqdesc *desc)
{
	if (desc->chip->ack)
		desc->chip->ack(desc);
}

static inline void irq_mask(struct irqdesc *desc)
{
	if (desc->chip->mask)
		desc->chip->mask(desc);
}

static inline void irq_mask_ack(struct irqdesc *desc)
{
	if (desc->chip->mask_ack)
		desc->chip->mask_ack(desc);
	else {
		irq_mask(desc);
		irq_ack(desc);
	}
}

static inline void irq_unmask(struct irqdesc *desc)
{
	if (desc->chip->unmask)
		desc->chip->unmask(desc);
}

#endif
