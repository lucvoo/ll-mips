/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_MEMORY_H_
#define	_ARCH_MEMORY_H_

#define	KSEG2_BASE	0xC0000000
#define	KSEG1_BASE	0xA0000000
#define	KSEG0_BASE	0x80000000
#define	KUSEG_BASE	0x00000000

#define	PHYS_ADDR	KSEG0_BASE
#define	VIRT_ADDR	KSEG0_BASE

#define	TEXT_OFFSET	CONFIG_TEXT_OFFSET

#endif
