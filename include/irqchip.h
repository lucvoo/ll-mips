/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_IRQCHIP_H_
#define	_IRQCHIP_H_

#include <iomem.h>
#include <irqdesc.h>


struct irqchip {
	const char		*name;
	void __iomem		*iobase;
	void			(*ack)(struct irqdesc *desc);
	void			(*mask)(struct irqdesc *desc);
	void			(*mask_ack)(struct irqdesc *desc);
	void			(*unmask)(struct irqdesc *desc);

	void			(*default_handler)(struct irqdesc *desc);

	struct irqdesc		*parent;
	struct irqchip		*next;

	unsigned short		irq_nbr;
	struct irqdesc		*descs;
};

void irqchip_init(struct irqchip *chip);

#endif
