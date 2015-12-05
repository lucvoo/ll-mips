/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_INIT_H_
#define	_INIT_H_

void soc_init(void);
void soc_irq_init(void);
void arch_irq_init(void);
void board_init(void);
void timer_init(void);
void timerdev_init(void);

#endif
