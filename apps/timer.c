/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <kapi.h>
#include <diag.h>
#include <timer.h>
#include <idle.h>


static void timer_action(void *data)
{
	const ulong *delay = data;

	diag_puts("\nt = ");
	diag_hexval(*delay);
}

void main(void)
{
	ulong cnt = 0;

	while (1) {
		cnt++;
		timer(HZ, timer_action, &cnt);
		idle();
		diag_putc('.');
	}
}
