#include <stdint.h>
#include <stdio.h>

// Define GPIO registers and bit masks based on FE310-G002 manual
#define GPIO_BASE        0x10012000
#define GPIO_INPUT_VAL   (GPIO_BASE + 0x04)  // Input values
#define GPIO_OUTPUT_EN   (GPIO_BASE + 0x08)  // Output enable
#define GPIO_OUTPUT_VAL  (GPIO_BASE + 0x0C)  // Output values
#define GPIO_PIN         (1 << 5)            // Select GPIO pin 5

void delay(uint32_t microseconds) {
    // Simple delay loop
    volatile uint32_t count;
    for (count = 0; count < microseconds * 10; ++count) {
        // Busy-wait loop
    }
}

int main(void) {
    printf("Direct GPIO Access Example\n");

    // Example: Set GPIO pin 5 as output
    *(volatile uint32_t*)GPIO_OUTPUT_EN |= GPIO_PIN;

    // Blink loop
    while (1) {
        // Turn OFF pin
        *(volatile uint32_t*)GPIO_OUTPUT_VAL &= ~GPIO_PIN;
        printf("LED OFF\n");
        delay(200000); // 2 seconds

        // Turn ON pin
        *(volatile uint32_t*)GPIO_OUTPUT_VAL |= GPIO_PIN;
        printf("LED ON\n");
        delay(200000); // 2 seconds
    }

    return 0;
}

