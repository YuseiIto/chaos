#ifndef _REGDEFS_H_
#define _REGDEFS_H_
#include <stdint.h>

typedef volatile uint32_t reg_t;
typedef volatile struct{
reg_t DR;     /* 0x0  Data Register */
reg_t RSRECR; /* 0x4 */
volatile uint8_t reserved1[16]; /* 16 Bytes Reserved Space */
reg_t FR;   /* 0x18 Flag Register */
reg_t ILPR; /* 0x20 Not in use */
reg_t IBRD; /* 0x24 Integer baud rate divisor */
reg_t FBRD; /* 0x28 Fractional baud rate divisor */
reg_t LCRH; /* 0x2c Line Control Register */
reg_t CR;   /* 0x30 Control Register */
reg_t IFLS; /* 0x34 Interrupt FIFO Level Select Register */
reg_t IMSC; /* 0x38 Interrupt Mask Set Clear Register */
reg_t RIS;  /* 0x3c Raw interrupt Status Register */
reg_t MIS;  /* 0x40 Masked Interrupt Status Register */
reg_t ICR;  /* 0x44 Interrupt Clear Register */
reg_t DMACR;/* 0x48 DMA Control Register */
volatile uint8_t reserved2[52]; /* 52 Bytes Reserved Space */
reg_t ITCR; /* 0x80 Test Control Register */
reg_t ITIP; /* 0x84 Integration Test Input Register */
reg_t ITOP; /* 0x88 Integration Test Output Register */
reg_t TDR;  /* 0x8c Test data Register */
}UART_t;

#endif
