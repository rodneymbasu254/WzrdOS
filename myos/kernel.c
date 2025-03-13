/* kernel.c */
#include <stdint.h>

void uart_putc(char c) {
    /* Implement UART output (hardware-specific) */
    volatile uint32_t *uart_data = (volatile uint32_t *)0x101f1000; //Example uart address
    *uart_data = (uint32_t)c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

void kernel_main(void) {
    uart_puts("Hello, World! from my ARM OS!\n");
    while (1); // Simple loop
}