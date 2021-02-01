#include <stdint.h>
#include "uart.h"

uint32_t get_core_id(void)
{
    uint64_t id;
    __asm__ volatile("mrs %0, mpidr_el1" : "=r" (id));
    id &= 0xff;
    return id;
}

void system_init(){
    if (get_core_id() != 0) {
        while (1) { io_hlt(); }
    }
    
    uart_init();
    uart_puts("\n\n=================================\n");
    uart_puts("osos Operating System By Yusei Ito\n");
    uart_puts("=================================\n");
    
}


void main(void)
{
    system_init();

    while (1){
     volatile int i=0;
        for(i=0;i<20000000;i++){}
        uart_putHex((uint32_t)0x08,2);
    }
}
