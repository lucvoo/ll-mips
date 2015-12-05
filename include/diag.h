/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_DIAG_H_
#define	_DIAG_H_

void diag_putc(unsigned int c);
void diag_puts(const char* str);
void diag_putb(const char* str, unsigned int n);

void diag_hexval(unsigned long val);
void diag_hexdump(const char *msg, const void *buff, unsigned int len);

#endif
