/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef	_GENERIC_KINT_H_
#define	_GENERIC_KINT_H_

typedef __INT8_TYPE__		s8;
typedef __INT16_TYPE__		s16;
typedef __INT32_TYPE__		s32;
typedef __INT64_TYPE__		s64;
typedef __UINT8_TYPE__		u8;
typedef __UINT16_TYPE__		u16;
typedef __UINT32_TYPE__		u32;
typedef __UINT64_TYPE__		u64;


#ifdef	__CHECKER__
#define	__bitwise	__attribute__((bitwise))
#else
#define	__bitwise
#endif

typedef u16 __bitwise __be16;
typedef u32 __bitwise __be32;
typedef u64 __bitwise __be64;
typedef u16 __bitwise __le16;
typedef u32 __bitwise __le32;
typedef u64 __bitwise __le64;

#endif
