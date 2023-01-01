; Store numbers from 00H to 20H in internal RAM starting from memory location 40H
mov ax, 00H   ; load 00H into ax register
mov bx, 40H   ; load 40H into bx register (starting address for RAM)

store_loop:
  mov [bx], ax ; store value in ax at memory location pointed to by bx
  add ax, 1    ; increment ax by 1
  add bx, 2    ; increment bx by 2 (assuming each memory location is 2 bytes)
  cmp ax, 20H  ; compare ax to 20H
  jle store_loop  ; if ax is less than or equal to 20H, jump back to store_loop

; Extract only the prime numbers
call prime_subroutine  ; call the prime number subroutine

prime_subroutine:
  mov cx, 20H   ; load 20H into cx register (number of values to check)
  mov bx, 40H   ; load 40H into bx register (starting address for RAM)
  xor dx, dx    ; clear dx register

prime_loop:
  mov ax, [bx]  ; load value at memory location pointed to by bx into ax
  cmp ax, 2     ; compare ax to 2
  jle not_prime  ; if ax is less than or equal to 2, it is not prime
  mov dx, 2     ; load 2 into dx (divisor)

divide_loop:
  cmp dx, ax    ; compare dx to ax
  jge is_prime   ; if dx is greater than or equal to ax, jump to is_prime
  mov bx, ax    ; move ax into bx
  div dx        ; divide bx by dx and store result in ax (quotient)
  cmp dx, ax    ; compare dx to ax
  jl not_prime   ; if dx is less than ax, jump to not_prime
  inc dx        ; increment dx by 1
  jmp divide_loop  ; jump back to divide_loop

is_prime:
  ; code to handle prime number goes here
  jmp continue_loop  ; jump to continue_loop

not_prime:
  ; code to handle non-prime number goes here

continue_loop:
  add bx, 2     ; increment bx by 2
  dec cx        ; decrement cx by 1
  cmp cx, 0     ; compare cx to 0
  jg prime_loop  ; if cx is greater than 0, jump back to prime_loop
  ret            ; return from subroutine
