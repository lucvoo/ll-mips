#ifndef	_MIPS_REGS_H_
#define	_MIPS_REGS_H_

#ifdef	__ASSEMBLY__
#define	__COPRO_REG(R,S)	R, S
#else
#define	__COPRO_REG(R,S)	#R ", " #S
#endif

#define	c0_index	__COPRO_REG($0, 0)

#define	c0_random	__COPRO_REG($1, 0)

#define	c0_entrylo0	__COPRO_REG($2, 0)

#define	c0_entrylo1	__COPRO_REG($3, 0)

#define	c0_context	__COPRO_REG($4, 0)

#define	c0_contextconfig __COPRO_REG($4, 1)

#define	c0_pagemask	__COPRO_REG($5, 0)

#define	c0_pagegrain	__COPRO_REG($5, 1)

#define	c0_wired	__COPRO_REG($6, 0)

#define	c0_hwrena	__COPRO_REG($7, 0)

#define	c0_badvaddr	__COPRO_REG($8, 0)

#define	c0_count	__COPRO_REG($9, 0)

#define	c0_entryhi	__COPRO_REG($10, 0)

#define	c0_compare	__COPRO_REG($11, 0)

#define	c0_status	__COPRO_REG($12, 0)
#define		ST0_IE		(1 << 0)
#define		ST0_EXL		(1 << 1)
#define		ST0_ERL		(1 << 2)
#define		ST0_KSU		(3 << 3)
#define		ST0_UM		(1 << 4)
#define		ST0_IM0		(1 << 8)
#define		ST0_IM1		(1 << 9)
#define		ST0_IM2		(1 <<10)
#define		ST0_IM3		(1 <<11)
#define		ST0_IM4		(1 <<12)
#define		ST0_IM5		(1 <<13)
#define		ST0_IM6		(1 <<14)
#define		ST0_IM7		(1 <<15)
#define		ST0_NMI		(1 <<19)
#define		ST0_SR		(1 <<20)
#define		ST0_TS		(1 <<21)
#define		ST0_BEV		(1 <<22)
#define		ST0_FR		(1 <<26)
#define		ST0_RP		(1 <<27)
#define		ST0_CU0		(1 <<28)
#define		ST0_CU1		(1 <<29)

#define	c0_intctl	__COPRO_REG($12, 1)
#define		INTCTL_VS_OFF	5
#define		INTCTL_VS_MSK	((1 <<5) - 1)

#define	c0_srsctl	__COPRO_REG($12, 2)

#define	c0_srsmap	__COPRO_REG($12, 3)

#define	c0_cause	__COPRO_REG($13, 0)
#define		CAUSE_CODE_OFF	2
#define		CAUSE_CODE_MSK	0x0000007C
#define		CAUSE_IP0	(1 << 8)
#define		CAUSE_IP1	(1 << 9)
#define		CAUSE_IP2	(1 <<10)
#define		CAUSE_IP3	(1 <<11)
#define		CAUSE_IP4	(1 <<12)
#define		CAUSE_IP5	(1 <<13)
#define		CAUSE_IP6	(1 <<14)
#define		CAUSE_IP7	(1 <<15)
#define		CAUSE_IP_OFF	8
#define		CAUSE_IP_MSK	0x0000FF00
#define		CAUSE_WP	(1 <<22)
#define		CAUSE_IV	(1 <<23)
#define		CAUSE_PCI	(1 <<26)
#define		CAUSE_DC	(1 <<27)
#define		CAUSE_TI	(1 <<30)
#define		CAUSE_BD	(1 <<31)

#define	c0_epc		__COPRO_REG($14, 0)

#define	c0_prid		__COPRO_REG($15, 0)

#define	c0_ebase	__COPRO_REG($15, 1)

#define	c0_config	__COPRO_REG($16, 0)
#define		CFG0_K0		(1 << 0)
#define		CFG0_VI		(1 << 3)
#define		CFG0_MT		(1 << 7)
#define		CFG0_AR		(1 <<10)
#define		CFG0_AT		(1 <<13)
#define		CFG0_BE		(1 <<15)
#define		CFG0_M		(1 <<31)

#define	c0_config1	__COPRO_REG($16, 1)
#define		CFG1_FP		(1 << 0)
#define		CFG1_EP		(1 << 1)
#define		CFG1_CA		(1 << 2)
#define		CFG1_WR		(1 << 3)
#define		CFG1_PC		(1 << 4)
#define		CFG1_MMU_SIZE1	(1 <<25)
#define		CFG1_M		(1 <<31)

#define	c0_config2	__COPRO_REG($16, 2)
#define		CFG2_M		(1 <<31)

#define	c0_config3	__COPRO_REG($16, 3)
#define		CFG3_VINT	(1 << 5)
#define		CFG3_VEIC	(1 << 6)
#define		CFG3_M		(1 <<31)

#define	c0_config6	__COPRO_REG($16, 6)

#define	c0_config7	__COPRO_REG($16, 7)

#define	c0_lladdr	__COPRO_REG($17, 0)

#define	c0_watchlo	__COPRO_REG($18, 0)

#define	c0_watchhi	__COPRO_REG($19, 0)

#define	c0_xcontext	__COPRO_REG($20, 0)

#define	c0_debug	__COPRO_REG($23, 0)

#define	c0_tracecontrol	__COPRO_REG($23, 1)

#define	c0_tracecontrol2 __COPRO_REG($23, 2)

#define	c0_usertracedata __COPRO_REG($23, 3)

#define	c0_tracebpc	__COPRO_REG($23, 4)

#define	c0_depc		__COPRO_REG($24, 0)

#define	c0_perfcnt	__COPRO_REG($25, 0)

#define	c0_errctl	__COPRO_REG($26, 0)

#define	c0_cacheerr	__COPRO_REG($27, 0)

#define	c0_taglo	__COPRO_REG($28, 0)

#define	c0_datalo	__COPRO_REG($28, 1)

#define	c0_taglo1	__COPRO_REG($28, 2)

#define	c0_datalo1	__COPRO_REG($28, 3)

#define	c0_taglo2	__COPRO_REG($28, 4)

#define	c0_datalo2	__COPRO_REG($28, 5)

#define	c0_taglo3	__COPRO_REG($28, 6)

#define	c0_datalo3	__COPRO_REG($28, 7)

#define	c0_taghi	__COPRO_REG($29, 0)

#define	c0_datahi	__COPRO_REG($29, 1)

#define	c0_taghi1	__COPRO_REG($29, 2)

#define	c0_datahi1	__COPRO_REG($29, 3)

#define	c0_taghi2	__COPRO_REG($29, 4)

#define	c0_datahi2	__COPRO_REG($29, 5)

#define	c0_taghi3	__COPRO_REG($29, 6)

#define	c0_datahi3	__COPRO_REG($29, 7)

#define	c0_errorepc	__COPRO_REG($30, 0)

#endif
