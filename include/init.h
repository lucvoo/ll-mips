#ifndef	_INIT_H_
#define	_INIT_H_

void soc_init(void);
void soc_irq_init(void);
void arch_irq_init(void);
void board_init(void);
void timer_init(void);
void timerdev_init(void);

#endif
