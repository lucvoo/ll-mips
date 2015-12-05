#ifndef	_TIMER_H_
#define	_TIMER_H_

#include <hz.h>

void timer(ulong delay, void (*action)(void *), void *data);

#endif
