.align 4
.section ".text.start"
.globl _start
#define MODE_AARCH64_EL2H 0x9

_start:
    msr DAIFClr, #0x0f // Disable interrupt
    ldr x0,=vector_table_el2
    msr VBAR_EL2, x0

    // Switch EL from EL3 to EL2
    // Reference: https://qiita.com/eggman/items/e500ecb33f8f126c0052
    mov   x0, #0x4b1    // RW=1, SMD=1, RES=1, NS=1
    msr   scr_el3, x0   // Secure Configuration Register: https://developer.arm.com/documentation/ddi0434/c/system-control/register-descriptions/secure-configuration-register

    adr   x0, start_el2 // Start from start_el2 after next `eret`
    msr   elr_el3, x0

    mov   x0, #MODE_AARCH64_EL2H
    msr   spsr_el3, x0
    eret

    start_el2:
    ldr x0,=__stack_start
    mov sp,x0  // Setup the stack.
    bl bss_clear
    bl main
    b finish

.section ".text"

bss_clear:
    ldr x1, =__bss_start
    ldr x2, =__bss_end

1:
    cmp x1,x2
    beq 2f
    str wzr,[x1]
    add x1,x1,#4
    b 1b
2:
    ret

.globl io_hlt
io_hlt:
    wfe
    ret

finish:
    wfe
    b finish
