#include <diag.h>


void diag_hexval(unsigned long val)
{
	int n;

	for (n = sizeof(val)*2; n--;) {
		unsigned int d = (val >> (4*n)) & 0xf;

		if (d > 9)
			d += 'A' - 10;
		else
			d += '0';

		diag_putc(d);
	}
}
