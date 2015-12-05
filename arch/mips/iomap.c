/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <io.h>
#include <arch/memory.h>


void __iomem *ioremap(ulong phys, ulong size)
{
	// FIXME
	return (void __iomem *) (KSEG1_BASE + phys);
}
