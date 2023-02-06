#include <stdio.h>
#include <stdint.h>

int main() {
// Get the value to be divided from RAM location 3EH
uint8_t value = (uint8_t)0x3E; // Note: You may need to use a different syntax to access RAM depending on your microcontroller

// Initialize the quotient to 0 and the remainder to the value
uint8_t quotient = 0;
uint8_t remainder = value;

// Divide value by 12H using looping and successive subtraction
while (remainder >= 0x12) {
quotient++;
remainder -= 0x12;
}

// Store the quotient in register R4 and the remainder in register R5
uint8_t R4 = quotient;
uint8_t R5 = remainder;

return 0;
}