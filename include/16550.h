#ifndef	_HW_16550_H_
#define	_HW_16550_H_

#define	UART_RBR	0	// Receive Buffer (RO, DLAB=0)

#define	UART_THR	0	// Transmit Holding (WO, DLAB=0)

#define	UART_IER	1	// Interrupt Enable (DLAB=0)
#define	UART_IER_RD		0x01	// Receiver Data
#define	UART_IER_THRE		0x02	// Transmitter Holding Register Empty
#define	UART_IER_RLS		0x04	// Receiver Line Status
#define	UART_IER_MS		0x08	// Modem Status

#define	UART_IIR	2	// Interrupt Ident (RO)
#define	UART_IIR_NOINT		0x01	// No interrupt
#define	UART_IIR_RLS		0x06	// Receiver Line Status
#define	UART_IIR_RD		0x04	// Receiver Data
#define	UART_IIR_RXTO		0x0c	// RX TimeOut
#define	UART_IIR_THRE		0x02	// Transmitter Holding Register Empty
#define	UART_IIR_MS		0x00	// Modem Status
#define	UART_IIR_MASK		0x0e	// Mask for ID

#define	UART_FCR	2	// FIFO Control (WO)
#define	UART_FCR_FIFOE		0x01	// FIFO Enable
#define	UART_FCR_RXR		0x02	// RX Fifo Reset
#define	UART_FCR_TXR		0x04	// TX Fifo Reset
#define	UART_FCR_DME		0x08	// DMA Enable
#define	UART_FCR_UME		0x10	// Uart Module Enable (JZ47xx specific)
#define	UART_FCR_T_TRIG_00	0x00
#define	UART_FCR_T_TRIG_01	0x10
#define	UART_FCR_T_TRIG_10	0x20
#define	UART_FCR_T_TRIG_11	0x30
#define	UART_FCR_T_TRIG_MASK	0x30
#define	UART_FCR_R_TRIG_00	0x00
#define	UART_FCR_R_TRIG_01	0x40
#define	UART_FCR_R_TRIG_10	0x80
#define	UART_FCR_R_TRIG_11	0xc0
#define	UART_FCR_R_TRIG_MASK	0xc0

#define	UART_LCR	3	// Line Control
#define	UART_LCR_WLEN5		0x00	// Word LENght: 5 bits
#define	UART_LCR_WLEN6		0x01	// Word LENght: 6 bits
#define	UART_LCR_WLEN7		0x02	// Word LENght: 7 bits
#define	UART_LCR_WLEN8		0x03	// Word LENght: 8 bits
#define	UART_LCR_STOP		0x04	// Stop bit: 1 bit / 2 bits
#define	UART_LCR_PARITY		0x08	// Parity
#define	UART_LCR_EPAR		0x10	// Even Parity
#define	UART_LCR_SPAR		0x20	// Sticky Parity
#define	UART_LCR_BRK		0x40	// Break
#define	UART_LCR_DLAB		0x80	// Divisor Latch Access Bit

#define	UART_MCR	4	// Modem Control
#define	UART_MCR_DTR		0x01	// DTR (reverse logic)
#define	UART_MCR_RTS		0x02	// RTS (reverse logic)

#define	UART_LSR	5	// Line Status
#define	UART_LSR_DR		0x01	// Data Ready
#define	UART_LSR_OE		0x02	// Overrun Error
#define	UART_LSR_PE		0x04	// Parity Error
#define	UART_LSR_FE		0x08	// Frame Error
#define	UART_LSR_BI		0x10	// Break Indicator
#define	UART_LSR_THRE		0x20	// Transmitter Holding Register Empty
#define	UART_LSR_TEMT		0x40	// Transmitter Empty
#define	UART_LSR_RFE		0x80	// RX FIFO Error

#define	UART_MSR	6	// Modem Status
#define	UART_MSR_DCTS		0x01	// Delta CTS
#define	UART_MSR_DDSR		0x02	// Delta DSR
#define	UART_MSR_TERI		0x04	// Trailing Edge Ring Indicator
#define	UART_MSR_DDCD		0x08	// Delta DCD
#define	UART_MSR_CTS		0x10	// Clear to Send
#define	UART_MSR_DSR		0x20	// Data Set Ready
#define	UART_MSR_RI		0x40	// Ring Indicator
#define	UART_MSR_DCD		0x80	// Data Carrier Detect

#define	UART_SCR	7	// SCratch

#define	UART_DLL	0	// Divisor Latch Least Significant (DLAB=1)

#define	UART_DLM	1	// Divisor Latch Most Significant (DLAB=1)

#endif
