#define	GPIO_PORT_REG(P, R)	((P)*0x100 + (R))

#define GPIO_PIN(P)	GPIO_PORT_REG(P, 0x00)	// PIN Level
#define GPIO_INT(P)	GPIO_PORT_REG(P, 0x10)	// Interrupt
#define GPIO_INTS(P)	GPIO_PORT_REG(P, 0x14)	// Interrupt Set
#define GPIO_INTC(P)	GPIO_PORT_REG(P, 0x18)	// Interrupt Clear
#define GPIO_MSK(P)	GPIO_PORT_REG(P, 0x20)	// Interrupt Mask
#define GPIO_MSKS(P)	GPIO_PORT_REG(P, 0x24)	// Interrupt Mask Set Reg
#define GPIO_MSKC(P)	GPIO_PORT_REG(P, 0x28)	// Interrupt Mask Clear Reg
#define GPIO_PAT1(P)	GPIO_PORT_REG(P, 0x30)	// Pattern 1
#define GPIO_PAT1S(P)	GPIO_PORT_REG(P, 0x34)	// Pattern 1 Set Reg.
#define GPIO_PAT1C(P)	GPIO_PORT_REG(P, 0x38)	// Pattern 1 Clear Reg.
#define GPIO_PAT0(P)	GPIO_PORT_REG(P, 0x40)	// Pattern 0
#define GPIO_PAT0S(P)	GPIO_PORT_REG(P, 0x44)	// Pattern 0 Set
#define GPIO_PAT0C(P)	GPIO_PORT_REG(P, 0x48)	// Pattern 0 Clear
#define GPIO_FLG(P)	GPIO_PORT_REG(P, 0x50)	// Flag
#define GPIO_FLGC(P)	GPIO_PORT_REG(P, 0x58)	// Flag clear
#define GPIO_OEN(P)	GPIO_PORT_REG(P, 0x60)	// Output Disable
#define GPIO_OENS(P)	GPIO_PORT_REG(P, 0x64)	// Output Disable Set
#define GPIO_OENC(P)	GPIO_PORT_REG(P, 0x68)	// Output Disable Clear
#define GPIO_PDIS(P)	GPIO_PORT_REG(P, 0x70)	// Pull Disable
#define GPIO_PDISS(P)	GPIO_PORT_REG(P, 0x74)	// Pull Disable Set
#define GPIO_PDISC(P)	GPIO_PORT_REG(P, 0x78)	// Pull Disable Clear
#define GPIO_DS(P)	GPIO_PORT_REG(P, 0x80)	// Drive Strength
#define GPIO_DSS(P)	GPIO_PORT_REG(P, 0x84)	// Drive Strength set
#define GPIO_DSC(P)	GPIO_PORT_REG(P, 0x88)	// Drive Strength clear

#define GPIO_DRVL(P)	GPIO_PORT_REG(P, 0x80)	// ?? Drive Low ??
#define GPIO_DRVLS(P)	GPIO_PORT_REG(P, 0x84)	// ?? Drive Low ?? set
#define GPIO_DRVLC(P)	GPIO_PORT_REG(P, 0x88)	// ?? Drive Low ?? clear
#define GPIO_DIR(P)	GPIO_PORT_REG(P, 0x80)	// ?? Direction ??
#define GPIO_DIRS(P)	GPIO_PORT_REG(P, 0x84)	// ?? Direction ?? set
#define GPIO_DIRC(P)	GPIO_PORT_REG(P, 0x88)	// ?? Direction ?? clear
#define GPIO_DRVH(P)	GPIO_PORT_REG(P, 0xA0)	// ?? Drive High ??
#define GPIO_DRVHS(P)	GPIO_PORT_REG(P, 0xA4)	// ?? Drive High ?? set
#define GPIO_DRVHC(P)	GPIO_PORT_REG(P, 0xA8)	// ?? Drive High ?? clear
