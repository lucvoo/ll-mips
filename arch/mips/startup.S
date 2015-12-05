#include <arch/regs-copro.h>
#include <arch/regs-alias.h>


// FIXME: this is cpu/subarch specific
#define	ST0_CLRMSK	(ST0_KSU|ST0_BEV|ST0_ERL|ST0_EXL|ST0_IE)
#define	ST0_SETMSK	0

	.section	".startup.text","ax"
	.global	__startup
	.type	__startup, @function
	.ent	__startup

__startup:

	// init the status register
	mfc0	t0, c0_status
	or	t0, t0, ST0_CLRMSK|ST0_SETMSK
	xor	t0, t0, ST0_CLRMSK
	mtc0	t0, c0_status
	ehb


	// end of PIC code
	la	t0, 1f
	jr	t0	
1:

	// clear cp0 context
	mtc0	$0, c0_context

        // initialize stack
	la	sp, __startup_stack + CONFIG_STARTUP_STACK_SIZE

	// initialize exception vectors
	la	t0, __ex_base
	mtc0	t0, c0_ebase

	// continue with C code
	j	__main

	.end	__startup
	.size	__startup, .-__startup
