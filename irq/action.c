/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <interrupt.h>
#include <irqdesc.h>
#include <errno.h>


void irq_create(struct irqaction* action, isr_handler_t handler, void* data)
{
	action->handler	= handler;
	action->data	= data;
}

int irq_attach(struct irqdesc *desc, struct irqaction* action)
{
	if (!desc)
		return -EINVAL;

	desc->action = action;

	return 0;
}
