#include <bitops/findbit.h>
#include <irqchip.h>
#include <soc/intc.h>
#include <arch/irq.h>
#include <soc/irq.h>
#include <io.h>
#include <irq.h>
#include <init.h>


#define	NBR_IRQS	IRQ_INTC_NBR


static void jz4780_intc_irq_mask(struct irqdesc *desc)
{
	uint irq = desc->irq;

	iowrite32(desc->chip->iobase + INTC_ICMSR(irq / 32), 1 << (irq % 32));
}

static void jz4780_intc_irq_unmask(struct irqdesc *desc)
{
	uint irq = desc->irq;

	iowrite32(desc->chip->iobase + INTC_ICMCR(irq / 32), 1 << (irq % 32));
}


static struct irqdesc jz4780_irq_descs[NBR_IRQS];
struct irqchip irqchip_intc;

static void jz4780_intc_irq_handler(struct irqdesc *desc)
{
	void __iomem *iobase = irqchip_intc.iobase;
	uint n = 0;
	uint irqs;

again:
	irqs = ioread32(iobase + INTC_ICPR(0));
	if (irqs) {
		do {
			uint irq;

			irq = bitop_ctz(irqs);
			irqs ^= 1 << irq;
			irq_handle_desc(&jz4780_irq_descs[irq +  0]);
		} while (irqs);

		n++;
		goto again;
	}

	irqs = ioread32(iobase + INTC_ICPR(1));
	if (irqs) {
		do {
			uint irq;

			irq = bitop_ctz(irqs);
			irqs ^= 1 << irq;
			irq_handle_desc(&jz4780_irq_descs[irq + 32]);
		} while (irqs);

		n++;
		goto again;
	}

	if (n == 0)
		return;	// FIXME: spurious interrupt
}


void soc_irq_init(void)
{
	struct irqchip *chip = &irqchip_intc;
	struct irqdesc *parent;
	void __iomem *iobase;

	parent = irq_get_desc(&irqchip_mips, IRQ_CPU_INTC);
	parent->handler = jz4780_intc_irq_handler;

	iobase = ioremap(INTC_BASE, INTC_SIZE);

	chip->irq_nbr	= NBR_IRQS;
	chip->descs	= jz4780_irq_descs;
	chip->iobase	= iobase;
	chip->parent	= parent;

	chip->mask	= jz4780_intc_irq_mask;
	chip->mask_ack	= jz4780_intc_irq_mask;
	chip->unmask	= jz4780_intc_irq_unmask;

	// Mask all the interrupts
	iowrite32(chip->iobase + INTC_ICMSR(0), 0xffffffff);
	iowrite32(chip->iobase + INTC_ICMSR(1), 0xffffffff);

	irqchip_init(chip);
	irq_unmask(parent);
}
