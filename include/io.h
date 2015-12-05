#ifndef	_IO_H_
#define	_IO_H_

#include <arch/io.h>

void __iomem *ioremap(ulong phys, ulong size);

#endif
