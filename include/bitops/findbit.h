/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_BITOPS_FINDBIT_H_
#define	_BITOPS_FINDBIT_H_

/**
 * Find First (bit) Set
 *
 * 0		-> 0
 * XXXXXXX1	-> 1
 * XXXXXX10	-> 2
 * ...
 */
#define	bitop_ffs(val)	__builtin_ffsl(val)

/**
 * Count Trailing Zeroes
 *
 * 0		-> undef
 * XXXXXXX1	-> 0
 * XXXXXX10	-> 1
 * ...
 */
#define	bitop_ctz(val)	__builtin_ctzl(val)

/**
 * Count Leading Zeroes
 *
 * 0		-> undef
 * 1XXXXXXX	-> 0
 * 01XXXXXX	-> 1
 * ...
 */
#define	bitop_clz(val)	__builtin_clzl(val)

/**
 * Find Most Significant Bit
 *
 * 00000000	-> undef
 * 00000001	-> 0
 * 0000001X	-> 1
 * ...
 */
static inline unsigned long bitop_fmsb(unsigned long val)
{
	return sizeof(val)*8 - 1 - __builtin_clzl(val);
}

#endif
