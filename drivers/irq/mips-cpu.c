/*
 * (C) Copyright 2009 Luc Van Oostenryck <luc.vanoostenryck@gmail.com>
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

/*
 * Driver for the internal 8 interrupts found in MIPS CPUs.
 * It's the root for others interrupt controller(s) that may be connected.
 *
 * The first two (IP0 & IP1) are software interrupts (needed for SMP).
 * The others are hardware interrupt sources.
 */

#include <irqchip.h>
#include <arch/regs-copro.h>
#include <arch/copro.h>
#include <arch/hazard.h>
#include <arch/interrupt.h>
#include <init.h>


#define	NBR_IRQS	8

static void mips_irq_mask(struct irqdesc *desc)
{
	c0_clrbits(c0_status, ST0_IM0 << desc->irq);
	ehb();
}

static void mips_irq_unmask(struct irqdesc *desc)
{
	c0_setbits(c0_status, ST0_IM0 << desc->irq);
	ehb();
}


static struct irqdesc	mips_irq_descs[NBR_IRQS];
struct irqchip irqchip_mips;

void arch_irq_init(void)
{
	irqchip_mips.irq_nbr	= NBR_IRQS;
	irqchip_mips.descs	= mips_irq_descs;
	irqchip_mips.ack	= mips_irq_mask;
	irqchip_mips.mask	= mips_irq_mask;
	irqchip_mips.mask_ack	= mips_irq_mask;
	irqchip_mips.unmask	= mips_irq_unmask;

	irqchip_init(&irqchip_mips);
}

/*****************************************************************************/
#include <interrupt.h>
#include <bitops/findbit.h>

void mach_irq_handler(struct eframe *regs, unsigned int cause, unsigned int status)
{
	unsigned int irqs = (cause & status & CAUSE_IP_MSK) >> CAUSE_IP_OFF;

	if (!irqs)
		return;			// FIXME spurious interrupt

	do {
		unsigned int irq;

		irq = bitop_fmsb(irqs);
		irqs ^= 1 << irq;
		__irq_handler(&mips_irq_descs[irq], regs);
	} while (irqs);
}
