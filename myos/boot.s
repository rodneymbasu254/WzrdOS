.global _start
.extern kernel_main

.section .text

.equ UART0_BASE, 0x3F201000

_start:
    ldr sp, =0x8000

    ldr r0, =UART0_BASE
    ldr r1, =88
    str r1, [r0]

    bl kernel_main

    b .


