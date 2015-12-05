#include <diag.h>


void diag_puts(const char* str)
{
	unsigned int c;

	while ((c = *str++))
		diag_putc(c);
}

void diag_putb(const char* str, unsigned int n)
{
	while (n--)
		diag_putc(*str++);
}
