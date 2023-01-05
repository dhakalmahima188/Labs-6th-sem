#include<stdio.h>
#include <stdint.h>
void swap_with_rotate(uint8_t *reg) {
// Rotate the low nibble of the accumulator right
*reg = (*reg >> 4) | (*reg << 4);
}
int main(){
    uint8_t accumulator = 0x6B;
swap_with_rotate(&accumulator);
}