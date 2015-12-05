/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#define	DECLARE_STACK(name, size)	\
	char name[size] __attribute__((aligned(CONFIG_STACK_ALIGNMENT), section(".uninit." #name)))

#ifdef CONFIG_INTERRUPT_STACK_SIZE
DECLARE_STACK(__interrupt_stack, CONFIG_INTERRUPT_STACK_SIZE);
#endif

DECLARE_STACK(__exception_stack, CONFIG_EXCEPTION_STACK_SIZE);

#ifndef	CONFIG_FIXED_STACKS
DECLARE_STACK(__startup_stack, CONFIG_STARTUP_STACK_SIZE);
#endif
