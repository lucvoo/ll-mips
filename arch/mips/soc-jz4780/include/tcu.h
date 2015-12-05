#ifndef	_SOC_TCU_H_
#define	_SOC_TCU_H_

#define	TCU_CH_OST		15

#define	TCU_BASE	0x10002000
#define	TCU_SIZE	0x00000100
#define	TCU_TSTR	    0x00f0
#define	TCU_TFR		    0x0020
#define	TCU_TFSR	    0x0024
#define	TCU_TFCR	    0x0028
#define	TCU_TER		    0x0010
#define	TCU_TESR	    0x0014
#define	TCU_TECR	    0x0018
#define	TCU_TMR		    0x0030
#define	TCU_TMSR	    0x0034
#define	TCU_TMCR	    0x0038
#define	TCU_TSR		    0x001c
#define	TCU_TSSR	    0x002c
#define	TCU_TSCR	    0x003c

#define	TCU_TDFR(CH)	   (0x0040 + (CH) * 0x10)
#define	TCU_TDHR(CH)	   (0x0044 + (CH) * 0x10)
#define	TCU_TCNT(CH)	   (0x0048 + (CH) * 0x10)
#define	TCU_TCSR(CH)	   (0x004C + (CH) * 0x10)
#define	TCU_CSR_ENABLED		0x0007
#define	TCU_CSR_PCK_EN		0x0001	// select PCLK as clock
#define	TCU_CSR_RTC_EN		0x0002	// select RTCCLK as clock
#define	TCU_CSR_EXT_EN		0x0004	// select EXTAL as clock
#define	TCU_CSR_PRESCALE	0x0038
#define	TCU_CSR_DIV_1		0x0000
#define	TCU_CSR_DIV_4		0x0008
#define	TCU_CSR_DIV_16		0x0010
#define	TCU_CSR_DIV_64		0x0018
#define	TCU_CSR_DIV_256		0x0020
#define	TCU_CSR_DIV_1024	0x0028
#define	TCU_CSR_SD		0x0100
#define	TCU_CSR_CNT_MD		0x8000	// only for OST

#define	OST_CMP		    0x00e0
#define	OST_CNTL		    0x00e4
#define	OST_CNTH		    0x00e8
#define	OST_CNTH_BUF	    0x00fc
#define	OST_CSR		    0x00ec

#endif
