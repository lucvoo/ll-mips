#include <arch/asm-offsets.h>

.macro	save_regs_all
	.set push
	.set noat

	// TODO: check if we come from user space
	//       if so, switch to kernel stack
	//	 and restore 'current'

	move	k1,	sp
	subu	sp,	EF_SIZE
	sw	k1,	EF_SP(sp)
	sw	gp,	EF_GP(sp)

	sw	zero,	EF_ZERO(sp)	// May be needed by ...
	sw	ta,	EF_AT(sp)
	sw	v0,	EF_V0(sp)
	sw	v1,	EF_V1(sp)

	sw	a0,	EF_A0(sp)
	sw	a1,	EF_A1(sp)
	sw	a2,	EF_A2(sp)
	sw	a3,	EF_A3(sp)

	sw	t0,	EF_T0(sp)
	sw	t1,	EF_T1(sp)
	sw	t2,	EF_T2(sp)
	sw	t3,	EF_T3(sp)
	sw	t4,	EF_T4(sp)
	sw	t5,	EF_T5(sp)
	sw	t6,	EF_T6(sp)
	sw	t7,	EF_T7(sp)
	sw	t8,	EF_T8(sp)
	sw	t9,	EF_T9(sp)

	sw	s0,	EF_S0(sp)
	sw	s1,	EF_S1(sp)
	sw	s2,	EF_S2(sp)
	sw	s3,	EF_S3(sp)
	sw	s4,	EF_S4(sp)
	sw	s5,	EF_S5(sp)
	sw	s6,	EF_S6(sp)
	sw	s7,	EF_S7(sp)

	sw	fp,	EF_FP(sp)

	sw	ra,	EF_RA(sp)

	mfhi	t0
	sw	t0,	EF_HI(sp)
	mflo	t1
	sw	t1,	EF_LO(sp)

	mfc0	t0,	c0_epc
	sw	t0,	EF_EPC(sp)
	mfc0	a1,	c0_cause
	sw	a1,	EF_CAUSE(sp)
	mfc0	a2,	c0_status
	sw	a2,	EF_STATUS(sp)
	.set pop
.endm

.macro	restore_regs_all
	.set push
	.set noat

	lw	a1,	EF_STATUS(sp)
	mtc0	a1,	c0_status
	lw	a0,	EF_CAUSE(sp)
	mtc0	a0,	c0_cause
	lw	t0,	EF_EPC(sp)
	mtc0	t0,	c0_epc

	lw	t1,	EF_LO(sp)
	mtlo	t1
	lw	t0,	EF_HI(sp)
	mthi	t0

	lw	ra,	EF_RA(sp)

	lw	fp,	EF_FP(sp)

	lw	s7,	EF_S7(sp)
	lw	s6,	EF_S6(sp)
	lw	s5,	EF_S5(sp)
	lw	s4,	EF_S4(sp)
	lw	s3,	EF_S3(sp)
	lw	s2,	EF_S2(sp)
	lw	s1,	EF_S1(sp)
	lw	s0,	EF_S0(sp)

	lw	t9,	EF_T9(sp)
	lw	t8,	EF_T8(sp)
	lw	t7,	EF_T7(sp)
	lw	t6,	EF_T6(sp)
	lw	t5,	EF_T5(sp)
	lw	t4,	EF_T4(sp)
	lw	t3,	EF_T3(sp)
	lw	t2,	EF_T2(sp)
	lw	t1,	EF_T1(sp)
	lw	t0,	EF_T0(sp)

	lw	a3,	EF_A3(sp)
	lw	a2,	EF_A2(sp)
	lw	a1,	EF_A1(sp)
	lw	a0,	EF_A0(sp)

	lw	v1,	EF_V1(sp)
	lw	v0,	EF_V0(sp)
	lw	ta,	EF_AT(sp)

	lw	gp,	EF_GP(sp)
	lw	sp,	EF_SP(sp)

	// TODO: user space/kernel space

	.set pop
.endm

