#ifndef	_IRQDESC_H_
#define	_IRQDESC_H_


struct irqaction;
struct irqchip;

struct irqdesc {
	void			(*handler)(struct irqdesc *desc);
	struct irqaction*	action;
	struct irqchip*		chip;
	unsigned int		irq;		// relative to the chip
};

struct irqdesc *irq_get_desc(struct irqchip *chip, unsigned int irq);


void irq_handle_desc(struct irqdesc *desc);

#endif
