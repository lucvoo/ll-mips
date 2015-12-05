/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_REGS_ALIAS_H_
#define	_REGS_ALIAS_H_


#define zero    $0	// fixed
#define ta      $1	// call clobered
#define v0      $2	// call clobered
#define v1      $3	// call clobered
#define a0      $4	// call clobered
#define a1      $5	// call clobered
#define a2      $6	// call clobered
#define a3      $7	// call clobered
#define a4      $8	// call clobered,	same as t0, eabi
#define a5      $9	// call clobered,	same as t1, eabi
#define a6      $10	// call clobered,	same as t2, eabi
#define a7      $11	// call clobered,	same as t3, eabi
#define t0      $8	// call clobered
#define t1      $9	// call clobered
#define t2      $10	// call clobered
#define t3      $11	// call clobered
#define t4      $12	// call clobered
#define t5      $13	// call clobered
#define t6      $14	// call clobered
#define t7      $15	// call clobered
#define t8      $24	// call clobered
#define t9      $25	// call clobered
#define s0      $16	// call preserved
#define s1      $17	// call preserved
#define s2      $18	// call preserved
#define s3      $19	// call preserved
#define s4      $20	// call preserved
#define s5      $21	// call preserved
#define s6      $22	// call preserved
#define s7      $23	// call preserved
#define s8      $30	// call preserved,	same as fp
#define gp      $28	// call preserved
#define sp      $29	// call preserved
#define fp      $30	// call preserved,	s8 if unused
#define ra      $31	// call preserved
#define k0      $26	// reserved
#define k1      $27	// reserved

#endif
