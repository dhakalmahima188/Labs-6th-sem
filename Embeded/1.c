#include <stdio.h>
#include <stdint.h>

// Function prototypes
void display_result(uint32_t result);



void display_result(uint32_t result) {
// Iterate through each byte of the result and display it on the LEDs
uint8_t i;
for (i = 0; i < 4; i++) {
// Extract the current byte
uint8_t byte = (result >> (8 * i)) & 0xFF;


}
}

void delay() {
// Insert code to implement a delay here
// You can use a for loop with some number of iterations to achieve this
}
int main() {
// Add the two hexadecimal numbers
uint32_t result = 0x897F9AH + 0x34BC48H;

// Display the result continuously on the LEDs
while (1) {
display_result(result);
}
return 0;
}