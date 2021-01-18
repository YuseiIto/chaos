.align 4
.section ".text.start"
.globl _start

_start:
    msr DAIFSet, #0x0f // Disable interrupt
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
