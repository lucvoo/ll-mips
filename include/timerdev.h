#ifndef _TIMERDEV_H_
#define _TIMERDEV_H_

#include <hz.h>


ulong timerdev_read(void);
void timerdev_next(ulong val);
void timerdev_handler(void);

#endif
