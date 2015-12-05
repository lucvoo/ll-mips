/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_ARCH_COPRO_H_
#define	_ARCH_COPRO_H_

#include <arch/regs-copro.h>


#define	c0_getval(REG_SEL)			\
	({	unsigned long __val;		\
		asm volatile(			\
		"mfc0	%0, " REG_SEL		\
		: "=r" (__val)			\
		);				\
		__val;				\
	})

#define	c0_setval(REG_SEL, VAL)			\
	({	unsigned long __val = VAL;	\
		asm volatile(			\
		"mtc0	%0, " REG_SEL "	\n\t"	\
		"ehb"				\
		:				\
		: "r" (__val)			\
		);				\
	})

#define	c0_setbits(REG_SEL, SET)				\
	({	unsigned long __old, __new;			\
		__old = c0_getval(REG_SEL);			\
		__new = __old | (SET);				\
		c0_setval(REG_SEL, __new);			\
		__old;						\
	})

#define	c0_clrbits(REG_SEL, CLR)				\
	({	unsigned long __old, __new;			\
		__old = c0_getval(REG_SEL);			\
		__new =  __old & ~(CLR);			\
		c0_setval(REG_SEL, __new);			\
		__old;						\
	})

#define	c0_xorbits(REG_SEL, VAL)				\
	({	unsigned long __old, __new;			\
		__old = c0_getval(REG_SEL);			\
		__new = __old ^ (VAL);				\
		c0_setval(REG_SEL, __new);			\
		__old;						\
	})

#define	c0_modbits(REG_SEL, SET, CLR)				\
	({	unsigned long __old, __new;			\
		__old = c0_getval(REG_SEL);			\
		__new = (__old | (SET)) & ~(CLR);		\
		c0_setval(REG_SEL, __new);			\
		__old;						\
	})

#define	c0_chgbits(REG_SEL, MSK, VAL)				\
	({	unsigned long __old, __new;			\
		__old = c0_getval(REG_SEL);			\
		__new = (__old & ~(MSK)) | ((VAL) & (MSK));	\
		c0_setval(REG_SEL, __new);			\
		__old;						\
	})

#endif
