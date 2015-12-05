/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <diag.h>


void diag_hexval(unsigned long val)
{
	int n;

	for (n = sizeof(val)*2; n--;) {
		unsigned int d = (val >> (4*n)) & 0xf;

		if (d > 9)
			d += 'A' - 10;
		else
			d += '0';

		diag_putc(d);
	}
}
