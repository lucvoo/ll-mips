/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_TIMER_H_
#define	_TIMER_H_

#include <hz.h>

void timer(ulong delay, void (*action)(void *), void *data);

#endif
