#include <io.h>
#include <arch/memory.h>


void __iomem *ioremap(ulong phys, ulong size)
{
	// FIXME
	return (void __iomem *) (KSEG1_BASE + phys);
}
