#include "mbed.h"

DigitalOut led(LED1);            // LED for visual feedback
BufferedSerial pc(USBTX, USBRX); // Serial for debugging output

#define STACK_SIZE 4    // Size of the stack (4 elements)
int stack[STACK_SIZE];  // Stack array
int top = 0;            // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        
        // Handle stack full case
        printf("Stack is full\n");
    }
    // Push value onto stack and increment top
    stack[top] = value;	
    top++;
}

int pop() {
    if (top <= 0) {
        
        // Handle stack empty case
        printf("Stack is empty\n");
    }
    // Decrement top and return the value
    top--;
    return stack[top];
}

void display_top() {
    if (top <= 0) {
        
        // Handle stack empty case
        printf("Stack is empty\n");
    }
    // Display the top value
    printf("Top value: %d\n", stack[top-1]);
}

int main() {
    // Push first value
    push(5);
    // Push second value
    push(10);

    display_top(); 	// Display top value after pushing

    // Pop the top value
    pop();

    display_top(); 	// Display new top value after popping

    while (1) {
        led = !led;      // Blink LED
        wait_us(500000); // Wait half a second
    }
}
