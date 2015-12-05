#ifndef	_ARCH_IRQ_H_
#define	_ARCH_IRQ_H_

#include <irqchip.h>

#define	NR_IRQS	256


extern struct irqchip irqchip_mips;
extern struct irqchip irqchip_intc;

#endif
