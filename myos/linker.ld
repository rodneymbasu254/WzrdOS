/* linker.ld */
ENTRY(_start)

SECTIONS {
    . = 0x80000000; /* Start address */
    .boot : { *(.text.boot) } /* Bootloader */
    . = 0x80001000; /* Kernel start address */
    .text : { *(.text) } /* Kernel code */
    .data : { *(.data) } /* Kernel data */
    .bss : { *(.bss) } /* Kernel BSS */
}