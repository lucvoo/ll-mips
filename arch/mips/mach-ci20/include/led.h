#include <io.h>


#define	GPIO_F_SET	0xb0010544
#define	GPIO_F_CLR	0xb0010548
#define	GPIO_F_LED	15

static inline void led(int state)
{
	if (state)
		iowrite32(GPIO_F_SET, 1 << GPIO_F_LED);
	else
		iowrite32(GPIO_F_CLR, 1 << GPIO_F_LED);
}
