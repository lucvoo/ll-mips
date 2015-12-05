/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_IRQFLAGS_H_
#define	_ARCH_IRQFLAGS_H_


static inline void irq_disable(void)
{
	asm volatile(
	"di				\n\t"
	"ehb				\n\t"
	:
	:
	: "memory");
}

static inline ulong irq_save(void)
{
	ulong flags;

	asm volatile(
	"di	%0			\n\t"
	"ehb				\n\t"
	: "=r" (flags)
	:
	: "memory");

	return flags;
}

static inline void irq_enable(void)
{
	asm volatile(
	"ei				\n\t"
	"ehb				\n\t"
	:
	:
	: "memory");
}

static inline void irq_restore(ulong flags)
{
	asm volatile(
	"mtc0	%0, $12			\n\t"
	"ehb				\n\t"
	:
	: "r" (flags)
	: "memory");
}

#endif
