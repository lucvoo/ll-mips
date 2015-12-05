/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <idle.h>
#include <irqflags.h>
#include <arch/idle.h>


void idle(void)
{
	irq_disable();
	mach_idle();
	irq_enable();
}
