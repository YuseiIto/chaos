#include "uart.h"

void current_el_spx_sync_el2_handler(uint32_t r0){
 uart_puts("EL2 SP0 Sync called.\n");
}

void current_el_spx_irq_el2_handler(uint32_t r0){
}

void current_el_spx_fiq_el2_handler(uint32_t r0){
}

void current_el_spx_serror_el2_handler(uint32_t r0){
}

void current_el_sp0_sync_el2_handler(uint32_t r0){
}

void current_el_sp0_irq_el2_handler(uint32_t r0){
}
