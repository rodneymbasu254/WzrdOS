#include <stdint.h>

#define UART0_BASE 0x3F201000  // Raspberry Pi 2 UART address

volatile uint32_t* const UART0_DR   = (uint32_t*)(UART0_BASE + 0x00);
volatile uint32_t* const UART0_FR   = (uint32_t*)(UART0_BASE + 0x18);

void uart_send(char c) {
    while (*UART0_FR & (1 << 5));  // Wait until TX FIFO is not full
    *UART0_DR = c;
}

void uart_print(const char* str) {
    while (*str) {
        uart_send(*str++);
    }
}

__attribute__((used)) __attribute__((section(".text"))) __attribute__((noreturn))
void kernel_main() {
    uart_print("Kernel is running...\n");
    while (1) {}  // Keep running
}
