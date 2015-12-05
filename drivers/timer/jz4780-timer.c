#include <timerdev.h>
#include <iomem.h>
#include <io.h>
#include <interrupt.h>
#include <init.h>
#include <irq.h>
#include <arch/memory.h>
#include <arch/irq.h>
#include <soc/tcu.h>
#include <soc/intc.h>
#include <soc/irq.h>

/*
 * The controller implement a few 16-bits timer, plus a 64-bits one (OST)
 *
 * The OST as a continuous counter.
 * One of the other timers is used as a one-shot timer.
 */

static struct timerdev {
	void __iomem *base;
} timerdev;

/**********************************************************************/

static int ostimer_isr(struct irqdesc *desc, void *data)
{
	unsigned int chan = TCU_CH_OST;

	iowrite32(timerdev.base + TCU_TFCR, 1 << chan);

	timerdev_handler();
	return IRQ_HANDLED;
}

ulong timerdev_read(void)
{
	ulong now = ioread32(timerdev.base + OST_CNTL);

	return now;
}

void timerdev_next(ulong val)
{
	void __iomem *iobase = timerdev.base;
	unsigned int chan = TCU_CH_OST;

	iowrite32(iobase + OST_CMP, val);
	iowrite32(iobase + TCU_TFCR, 1 << chan);
	iowrite32(iobase + TCU_TMCR, 1 << chan);
}

static struct irqaction ostimer_irq;


/**********************************************************************/
void timerdev_init(void)
{
	struct irqdesc *desc;
	void __iomem *base;

	base = ioremap(TCU_BASE, TCU_SIZE);
	if (!base)
		return;

	desc = irq_get_desc(&irqchip_intc, INTC_IRQ_TCU0);
	if (!desc)
		return;

	timerdev.base = base;

	irq_create(&ostimer_irq, ostimer_isr, &timerdev);
	irq_attach(desc, &ostimer_irq);

	iowrite32(base + OST_CNTL, 0);
	iowrite32(base + OST_CNTH, 0);
	iowrite32(base + OST_CMP, 0);
	iowrite32(base + OST_CSR, TCU_CSR_RTC_EN | TCU_CSR_DIV_1 | TCU_CSR_CNT_MD);

	iowrite32(base + TCU_TESR, 1 << TCU_CH_OST);
	irq_unmask(desc);
}
