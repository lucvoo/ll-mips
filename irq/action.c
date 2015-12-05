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
