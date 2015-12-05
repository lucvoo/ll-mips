/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_EXCEPTIONS_H_
#define	_EXCEPTIONS_H_

#include <arch/exceptions.h>


void dump_stack(const struct eframe *f, unsigned int flags);

// Handler for exceptions
void und_handler(const struct eframe *regs);

#endif
