OUTPUT_ARCH(aarch64) /* Specify output architecture */
ENTRY(_start) /* Specity the label of the entory point.*/

SECTIONS
{
    /* Starts at LOADER_ADDR. */
    . = 0x80000; /* 参考: https://tnishinaga.hatenablog.com/entry/2016/04/17/232617 */
    __start = .;
    __text_start = .;
    .text :
    {
        KEEP(*(.text.start))
        *(.text)
    }
    . = ALIGN(4096);
    __text_end = .;

    __rodata_start = .;
    .rodata :
    {
        *(.rodata)
    }
    . = ALIGN(4096);
    __rodata_end = .;

    __data_start = .;
    .data :
    {
        *(.data)
    }
    . = ALIGN(4096);
    __data_end = .;

    __bss_start = .;
    .bss :
    {
        bss = .;
        *(.bss)
    }
    . = ALIGN(4096);
    __bss_end = .;

    __heap_start = .;
    .heap :
    {
        heap = .;
        *(.heap)
    }
    . = ALIGN(4096);
    __heap_end = .;

    .stack :
    {
        __stack_end = .;
        __stack_start = __stack_end + (1024 * 1024) * 64;
    }

    __end = .;
}
