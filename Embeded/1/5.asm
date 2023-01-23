; Calculate the factorial of a number stored in R3
call factorial_subroutine  ; call the factorial subroutine

factorial_subroutine:
  mov ax, 1      ; load 1 into ax (factorial starts at 1)
  mov bx, 10     ; load 10 into bx (divisor for decimal conversion)
  mov cx, 0      ; clear cx (counter for decimal conversion)

factorial_loop:
  cmp R3, 0      ; compare R3 to 0
  je print_result   ; if R3 is 0, jump to print_result
  mul R3         ; multiply ax by R3 and store result in ax
  dec R3         ; decrement R3 by 1
  jmp factorial_loop  ; jump back to factorial_loop

print_result:
  ; code to print the factorial in hexadecimal format goes here
  ; (e.g. using the "mov ah, 0EH" and "int 10H" instructions to print a character)

  ; code to convert the factorial to decimal and print it goes here
  mov dx, 0      ; clear dx
  mov bx, 10     ; load 10 into bx (divisor for conversion)

convert_loop:
  mov dx, 0      ; clear dx
  div bx         ; divide ax by bx and store result in ax (quotient) and dx (remainder)
  add dx, '0'    ; convert remainder to ASCII character
  push dx        ; push ASCII character onto stack
  inc cx         ; increment cx (counter for number of digits)
  cmp ax, 0      ; compare ax to 0
  jne convert_loop  ; if ax is not 0, jump back to convert_loop

  ; code to print the decimal representation of the factorial goes here
  ; (e.g. using the "pop" and "mov ah, 0EH" instructions to pop characters off the stack and print them)
  ret             ; return from subroutine
