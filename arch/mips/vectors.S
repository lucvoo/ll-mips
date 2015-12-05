#include <arch/regs-copro.h>
#include <arch/regs-alias.h>
#include <arch/assembly.h>
#include <arch/eframe.S>

/*
 * 			ROM entry point		RAM entry point
 * 			Status.BEV == 1		Status.BEV == 0
 *
 * Reset & NMI		0xBFC00000		-
 * Simple TLB refill	0xBFC00200		BASE + 0x000
 * Cache error		0xBFC00300		BASE + 0x100 (forced into KSEG1)
 * Generic		0xBFC00380		BASE + 0x180
 * Interrupt Special	0xBFC00400		BASE + 0x200 (Cause.IV == 1)
 */

.macro	ex_entry
	save_regs_all

	// disable interrupts & errors & force kernel mode
	ori	a2, (ST0_IE|ST0_KSU|ST0_UM)
	xori	a2, (ST0_IE|ST0_KSU|ST0_UM)
	mtc0	a2, c0_status
	ehb
.endm


.align	12					// EBase must be 4K aligned

.global	__ex_base				// OFFSET 0x000
ENTRY(__ex_TLB_refill)
__ex_base:

	// FIXME/TODO

	eret
ENDFUN(__ex_TLB_refill)


.align	8					// OFFSET 0x100
ENTRY(__ex_cache_error)

	// FIXME/TODO

	eret
ENDFUN(__ex_cache_error)


.align	7					// OFFSET 0x180
ENTRY(__ex_generic)
	mfc0	k0, c0_cause
	andi	k0, k0, CAUSE_CODE_MSK

	lw	k1, __exception_vectors(k0)
	jr	k1
ENDFUN(__ex_generic)


.align	7					// OFFSET 0x200
ENTRY(vec_irq)
	ex_entry

	move	a0, sp
	la	ra, ret_from_interrupt
	j	mach_irq_handler
ENDFUN(vec_irq)

ENTRY(ret_from_interrupt)
	restore_regs_all
	eret
ENDFUN(ret_from_interrupt)


ENTRY(ret_from_exception)
	restore_regs_all
	eret
ENDFUN(ret_from_exception)


ENTRY(vec_unhandled)
	ex_entry

	move	a0, sp
	la	ra, ret_from_exception
	j	__handle_exceptions
ENDFUN(vec_unhandled)


ENTRY(vec_undef)
	ex_entry

	move	a0, sp
	la	ra, ret_from_exception
	j	__handle_undef
ENDFUN(vec_undef)


ENTRY(vec_tlb)
	ex_entry

	move	a0, sp
	la	ra, ret_from_exception
	j	__handle_tlb
ENDFUN(vec_tlb)



.section        .data,"aw",@progbits
.align  2
.type   __exception_vectors, @object
.size   __exception_vectors, 128
__exception_vectors:
        .word	vec_irq		// int (most probably taken by the dedicated vector (if c0_cause.IV == 1))
        .word	vec_tlb		// tlbm
        .word	vec_tlb		// tlbl
        .word	vec_tlb		// tlbs
        .word	vec_unhandled	// adel
        .word	vec_unhandled	// ades
        .word	vec_unhandled	// ibe
        .word	vec_unhandled	// dbe
        .word	vec_unhandled	// sys
        .word	vec_unhandled	// bp
        .word	vec_undef	// ri (Reserved/undefined Instruction)
        .word	vec_unhandled	// cpu
        .word	vec_unhandled	// ov
        .word	vec_unhandled	// tr
        .word	vec_unhandled
        .word	vec_unhandled	// fpe
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled	// c2e
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled	// mdmx
        .word	vec_unhandled	// watch
        .word	vec_unhandled	// mcheck
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled
        .word	vec_unhandled	// cacheerr
        .word	vec_unhandled
