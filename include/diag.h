#ifndef	_DIAG_H_
#define	_DIAG_H_

void diag_putc(unsigned int c);
void diag_puts(const char* str);
void diag_putb(const char* str, unsigned int n);

void diag_hexval(unsigned long val);
void diag_hexdump(const char *msg, const void *buff, unsigned int len);

#endif
