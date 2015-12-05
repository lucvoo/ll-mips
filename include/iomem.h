#ifndef	_IOMEM_H_
#define	_IOMEM_H_

#ifdef __CHECKER__
#define __force	__attribute__((force))
#define __iomem	__attribute__((noderef, address_space(2)))
extern void __chk_io_ptr(void __iomem *);
#else
#define __force
#define __iomem
#define __chk_io_ptr(x) (void)0
#endif

#endif
