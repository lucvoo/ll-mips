#include <diag.h>


static void diag_write_hexbyte(unsigned int val)
{
	unsigned int n;

	for (n = 2; n--;) {
		unsigned int d = (val >> (4*n)) & 0xf;

		if (d > 9)
			d += 'A' - 10;
		else
			d += '0';

		diag_putc(d);
	}
}

static void diag_hexdump_line(const unsigned char *buff, unsigned int len)
{
	unsigned int i;

	diag_hexval((unsigned long) buff);
	diag_puts(": ");

	// Hex part
	for (i = 0; i < len; i++) {
		diag_write_hexbyte(buff[i]);
		diag_putc(' ');
	}
	for (; i < 16; i++)
		diag_putb("   ", 3);

	diag_putc('\n');
}

void diag_hexdump(const char *msg, const void *buff, unsigned int len)
{
	if (msg) {
		diag_puts(msg);
		diag_putc('\n');
	}

	// Dump the buffer by lines of maximum 16 bytes
	while (len) {
		unsigned int n = len > 16 ? 16 : len;

		diag_hexdump_line(buff, n);
		buff += n;
		len -= n;
	}
}
