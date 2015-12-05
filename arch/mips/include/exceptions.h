/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_EFRAME_H_
#define	_ARCH_EFRAME_H_


struct eframe {
	unsigned long	r[32];
	unsigned long	hi;
	unsigned long	lo;

	unsigned long	status;
	unsigned long	cause;
	unsigned long	epc;

	unsigned long	padding;
};

#endif
