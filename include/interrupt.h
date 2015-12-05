#ifndef	_INTERRUPT_H_
#define	_INTERRUPT_H_


struct eframe;
struct irqdesc;

void __irq_handler(struct irqdesc *desc, struct eframe *regs);


typedef int (*isr_handler_t)(struct irqdesc *desc, void *);

// Return values for isr handlers
#define IRQ_NONE	0	// We didn't handled it
#define IRQ_HANDLED	1	// It was a valid interrupt and we handled it

struct irqaction {
	isr_handler_t	handler;
	void		*data;
};

int irq_attach(struct irqdesc *desc, struct irqaction* action);
void irq_create(struct irqaction*, isr_handler_t, void* data);

#endif
