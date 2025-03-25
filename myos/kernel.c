void uart_putc(char c) {
    volatile unsigned int *UART0 = (unsigned int *)0x09000000;
    *UART0 = (unsigned int)c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

int main(void) {
    uart_puts("Hello from ARM OS!\n");
    while (1);
    return 0;
}
