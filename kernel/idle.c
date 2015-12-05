#include <idle.h>
#include <irqflags.h>
#include <arch/idle.h>


void idle(void)
{
	irq_disable();
	mach_idle();
	irq_enable();
}
