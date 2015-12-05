#include <init.h>
#include <kapi.h>
#include <idle.h>


static void clear_bss(void)
{
	extern unsigned long __bss_start;
	extern unsigned long __bss_end;
	unsigned long* ptr = &__bss_start;
	unsigned long* end = &__bss_end;

	while (ptr < end) {
		*ptr++ = 0;
	}
}

static void init_data(void)
{
#ifdef	CONFIG_XIP
	extern const unsigned long __data_load;
	extern const unsigned long __data_end;
	extern unsigned long __data_start;

	const unsigned long *src = &__data_load;
	const unsigned long *end = &__data_end;
	unsigned long *dst = &__data_start;

	while (dst < end)
		*dst++ = *src++;
#endif
}


void __main(void)
{
	clear_bss();
	init_data();

	soc_init();
	arch_irq_init();
	soc_irq_init();
	timerdev_init();

	main();

	while (1)
		idle();
}
