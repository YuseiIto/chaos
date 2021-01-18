#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>
#include "regDefs.h"

#define UART_BASE 0x3F201000
#define UART0 ((UART_t *)UART_BASE)

volatile void uart_init();
volatile void uart_putc(volatile unsigned char c);
volatile void uart_puts(const char* str);
volatile unsigned char uart_getc();


#endif
