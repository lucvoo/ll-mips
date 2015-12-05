#ifndef	_EXCEPTIONS_H_
#define	_EXCEPTIONS_H_

#include <arch/exceptions.h>


void dump_stack(const struct eframe *f, unsigned int flags);

// Handler for exceptions
void und_handler(const struct eframe *regs);

#endif
