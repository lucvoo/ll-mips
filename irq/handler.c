/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <interrupt.h>
#include <irq.h>
#include <irqdesc.h>
#include <irqflags.h>


static struct irqdesc bad_irqdesc;


static int handle_isr(struct irqdesc *desc, struct irqaction *action)
{
	int ret;

	ret = action->handler(desc, action->data);
	// FIXME: check if handled

	return ret;
}

// handler for 'level' IRQ
static void irq_handle_level(struct irqdesc *desc)
{
	struct irqaction *action;

	irq_mask_ack(desc);
	action = desc->action;
	if (!action)		// leave it unmasked!
		return;

	handle_isr(desc, action);
	irq_unmask(desc);
}

void irq_handle_desc(struct irqdesc *desc)
{
	void (*handler)(struct irqdesc *) = desc->handler;

	if (handler)
		handler(desc);
	else
		irq_handle_level(desc);
}

// Normal entry for the main irqchip
void __irq_handler(struct irqdesc *desc, struct eframe *regs)
{

	(void) regs;

	if (!desc)
		desc = &bad_irqdesc;

	irq_handle_desc(desc);
}
