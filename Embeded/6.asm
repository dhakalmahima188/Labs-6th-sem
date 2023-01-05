; Store ten hexadecimal numbers in internal RAM starting from memory location 60H
mov ax, A5H  ; load A5H into ax
mov bx, 60H  ; load 60H into bx (starting address for RAM)
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2 (assuming each memory location is 2 bytes)

mov ax, FDH  ; load FDH into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 67H  ; load 67H into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 42H  ; load 42H into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, DFH  ; load DFH into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 9AH  ; load 9AH into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 84H  ; load 84H into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 1BH  ; load 1BH into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, C7H  ; load C7H into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx
add bx, 2    ; increment bx by 2

mov ax, 31H  ; load 31H into ax
mov [bx], ax ; store value in ax at memory location pointed to by bx

; Order the numbers in ascending order using bubble sort
call bubble_sort_ascending  ; call the bubble sort ascending subroutine

bubble_sort_ascending:
  mov cx, 10    ; load 10 into cx (number of values to sort)
  mov bx, 60H   ; load 60H into bx (starting address for RAM)

bubble_sort_ascending_loop:
  mov ax, [bx]  ; load value at memory location pointed to by bx into ax
  cmp ax, [bx+2]  ; compare ax to value at next memory location
  jge no_swap_ascending  ; if ax is greater than or equal to value at next memory location, jump to no_swap_ascending
  xchg
