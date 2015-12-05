/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <kapi.h>
#include <timer.h>
#include <idle.h>
#include <mach/led.h>
#include <diag.h>


static int state = 0;
static void timer_action(void *data)
{
	led(state);
	state = !state;
}

void main(void)
{
	led_init();
	while (1) {
		timer(HZ/2, timer_action, NULL);
		idle();
	}
}
