#include "uart.h"

volatile void uart_init(){
    // 1. Disable the UART
    UART0->CR  = 0x00000000;
    // 2. Wait for the end of transmisson/reception of current character
    while(UART0->FR & (0x1<<3)){}
    // 3.Flush the transmit FIFO by setting the FEN bit to 0 in the Line Control Register, UART_LCRH
    UART0->LCRH  &= 0b10000;
    // 4.Reprogram the Control Register
    UART0->LCRH  = 0b01100000;
    UART0->CR|=0x1<<8;
    // Set the baudrate
    UART0->IBRD= 26;
	   UART0->FBRD= 3;
    // 5.Enable the UART
    UART0->CR|= 0x1;
}

volatile void uart_putc(volatile unsigned char c)
{
    // Wait for UART to become ready to transmit.
    while (UART0->FR & (volatile uint32_t)(1 << 3) ) { }
    UART0->DR|=(volatile uint32_t)c;
}

volatile void uart_puts(const char* str)
{
    volatile int i;
    for (i = 0; str[i] != '\0'; i ++)
        uart_putc((volatile unsigned char)str[i]);
}

volatile unsigned char uart_getc()
{
    // Wait for UART to have received something.
    while (UART0->FR &  (volatile uint32_t)(1 << 4) ) { }
    return UART0->DR;
}

volatile void uart_putHex(uint32_t value,uint8_t column){
    char buf[9];
    char *p;
    p = buf + sizeof(buf) - 1;
    *(p--) = '\0';
    if(!value&&!column)
     column++;
    while(value||column){
        *(p--)="0123456789ABCDEF"[value & 0xf];
        value>>=4;
        if(column)column--;
    }
    uart_puts(p+1);
}
