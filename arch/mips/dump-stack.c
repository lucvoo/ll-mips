#include <exceptions.h>
#include <diag.h>


#define	DUMP(S, V)			\
	diag_puts(S);			\
	diag_putc(' ');			\
	diag_hexval(V)

#define	DUMP_LINE(SA,A,SB,B,SC,C,SD,D)	\
	DUMP(SA, A);			\
	DUMP(SB, B);			\
	DUMP(SC, C);			\
	DUMP(SD, D);			\
	diag_putc('\n')

void dump_stack(const struct eframe *f, unsigned int flags)
{
	DUMP_LINE("PC", f->epc, "  status", f->status, " cause", f->cause, " -", 0);
	DUMP_LINE("r0", f->r[ 0], ", at", f->r[ 1], ", v0", f->r[ 2], ", v1", f->r[ 3]);
	DUMP_LINE("a0", f->r[ 4], ", a1", f->r[ 5], ", a2", f->r[ 6], ", a3", f->r[ 7]);
	DUMP_LINE("t0", f->r[ 8], ", t1", f->r[ 9], ", t2", f->r[10], ", t3", f->r[11]);
	DUMP_LINE("t4", f->r[12], ", t5", f->r[13], ", t6", f->r[14], ", t7", f->r[15]);
	DUMP_LINE("s0", f->r[16], ", s1", f->r[17], ", s2", f->r[18], ", s3", f->r[19]);
	DUMP_LINE("s4", f->r[20], ", s5", f->r[21], ", s6", f->r[22], ", s7", f->r[23]);
	DUMP_LINE("t8", f->r[24], ", t9", f->r[25], ", k0", f->r[26], ", k1", f->r[27]);
	DUMP_LINE("gp", f->r[28], ", sp", f->r[29], ", fp", f->r[30], ", ra", f->r[31]);
}
