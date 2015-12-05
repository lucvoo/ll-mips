#ifndef	_ARCH_IO_H_
#define	_ARCH_IO_H_

#include <iomem.h>

#define iowrite8(a, v)	(__chk_io_ptr(a), *(volatile unsigned char  __force *)(a) = (v))
#define iowrite16(a, v)	(__chk_io_ptr(a), *(volatile unsigned short __force *)(a) = (v))
#define iowrite32(a, v)	(__chk_io_ptr(a), *(volatile unsigned long  __force *)(a) = (v))

#define ioread8(a)		(__chk_io_ptr(a), *(volatile unsigned char  __force *)(a))
#define ioread16(a)		(__chk_io_ptr(a), *(volatile unsigned short __force *)(a))
#define ioread32(a)		(__chk_io_ptr(a), *(volatile unsigned long  __force *)(a))

#endif
