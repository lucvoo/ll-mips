#ifndef	_SOC_REGS_COPRO_H_
#define	_SOC_REGS_COPRO_H_

#include <arch/regs-copro.h>

// JZ4780
#define	c0_core_ctrl	__COPRO_REG($12, 2)
#define	CORE_CTRL_SW_RST0	(1 <<  0)
#define	CORE_CTRL_SW_RST1	(1 <<  1)
#define	CORE_CTRL_RPC0		(1 <<  8)
#define	CORE_CTRL_RPC1		(1 <<  9)
#define	CORE_CTRL_SLEEP0	(1 << 16)
#define	CORE_CTRL_SLEEP1	(1 << 17)

#define	c0_core_stat	__COPRO_REG($12, 3)
#define	CORE_STATUS_MIRQ0	(1 <<  0)
#define	CORE_STATUS_MIRQ1	(1 <<  1)
#define	CORE_STATUS_IRQ0	(1 <<  8)
#define	CORE_STATUS_IRQ1	(1 <<  9)
#define	CORE_STATUS_SLEEP0	(1 << 16)
#define	CORE_STATUS_SLEEP1	(1 << 17)

#define	c0_core_reim	__COPRO_REG($12, 4)
#define	CORE_REIM_MIRQ0		(1 <<  0)
#define	CORE_REIM_MIRQ1		(1 <<  1)
#define	CORE_REIM_IRQ0		(1 <<  8)
#define	CORE_REIM_IRQ1		(1 <<  9)
#define	CORE_REIM_ENTRY_MSK	0xFFFF0000

/*
 * By default (when this bit is not set), the Xburst core will special casing
 * short loops to avoid BTB lookup.
 * This has as effect to vastly slow down tight, which we prefer to avoid!
 */
#define	CONFIG7_XBURST_SHORT_LOOPS_BTB_MAGIC	(1 << 4)

#define	c0_mailbox0	__COPRO_REG($20, 0)
#define	c0_mailbox1	__COPRO_REG($20, 1)

#endif
