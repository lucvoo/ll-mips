/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef _TIMERDEV_H_
#define _TIMERDEV_H_

#include <hz.h>


ulong timerdev_read(void);
void timerdev_next(ulong val);
void timerdev_handler(void);

#endif
