/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <irqdesc.h>
#include <irqchip.h>


struct irqdesc *irq_get_desc(struct irqchip *chip, unsigned int irq)
{
	if (!chip)
		return NULL;

	if (irq >= chip->irq_nbr)
		return NULL;

	return &chip->descs[irq];
}


void irqchip_init(struct irqchip *chip)
{
	unsigned int i;

	for (i = 0; i < chip->irq_nbr; i++) {
		struct irqdesc *desc = &chip->descs[i];

		desc->chip = chip;
		desc->irq = i;
		desc->handler = chip->default_handler;
	}
}
