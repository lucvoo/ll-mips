/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <diag.h>


void diag_puts(const char* str)
{
	unsigned int c;

	while ((c = *str++))
		diag_putc(c);
}

void diag_putb(const char* str, unsigned int n)
{
	while (n--)
		diag_putc(*str++);
}
