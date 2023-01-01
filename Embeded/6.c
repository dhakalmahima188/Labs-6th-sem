#include <stdio.h>
#include <stdint.h>

// Function prototypes
void bubble_sort_ascending(uint8_t *values, uint8_t num_values);
void selection_sort_descending(uint8_t *values, uint8_t num_values);

int main() {
// Store the hexadecimal numbers in internal RAM starting from memory location 60H
uint8_t values = (uint8_t)0x60; // Note: You may need to use a different syntax to access RAM depending on your microcontroller
values[0] = 0xA5;
values[1] = 0xFD;
values[2] = 0x67;
values[3] = 0x42;
values[4] = 0xDF;
values[5] = 0x9A;
values[6] = 0x84;
values[7] = 0x1B;
values[8] = 0xC7;
values[9] = 0x31;

// Sort the values in ascending order using the bubble sort algorithm
bubble_sort_ascending(values, 10);

// Sort the values in descending order using the selection sort algorithm
selection_sort_descending(values, 10);

return 0;
}

void bubble_sort_ascending(uint8_t *values, uint8_t num_values) {
// Perform the bubble sort algorithm to sort the values in ascending order
uint8_t i;
uint8_t j;
for (i = 0; i < num_values - 1; i++) {
for (j = 0; j < num_values - i - 1; j++) {
if (values[j] > values[j + 1]) {
// Swap the values if they are out of order
uint8_t temp = values[j];
values[j] = values[j + 1];
values[j + 1] = temp;
}
}
}
}

void selection_sort_descending(uint8_t *values, uint8_t num_values) {
// Perform the selection sort algorithm to sort the values in descending order
uint8_t i;
uint8_t j;
for (i = 0; i < num_values - 1; i++) {
// Find the index of the maximum value in the unsorted portion of the array
uint8_t max_index = i;
for (j = i + 1; j < num_values; j++) {
if (values[j] > values[max_index]) {
max_index = j;
}
}
// Swap the maximum value with the first element in the unsorted portion of the array
uint8_t temp = values[i];
values[i] = values[max_index];
values[max_index] = temp;
}
}