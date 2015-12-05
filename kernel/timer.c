#include <timer.h>
#include <timerdev.h>
#include <irqflags.h>


static struct timerdata {
	ulong	exp;
	void	(*action)(void *);
	void	*data;
} timerdata;

void timer(ulong delay, void (*action)(void *), void *data)
{
	ulong now = timerdev_read();
	ulong exp = now + delay;

	irq_disable();
	timerdata.exp = exp;
	timerdata.action = action;
	timerdata.data = data;

	timerdev_next(exp);
	irq_enable();
}

/******************************************************************************/
void timerdev_handler(void)
{
	ulong now = timerdev_read();
	long delta = timerdata.exp - now;

	if (delta > 0)
		return;

	timerdata.action(timerdata.data);
}
