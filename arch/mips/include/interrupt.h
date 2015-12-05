#ifndef	_ARCH_INTERRUPT_H_
#define	_ARCH_INTERRUPT_H_

struct eframe;

void mach_irq_handler(struct eframe *regs, uint cause, uint status);

#endif
