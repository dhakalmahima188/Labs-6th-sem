; Divide the data in RAM location 3EH by the number 12H
mov ax, [3EH]  ; load value at RAM location 3EH into ax
mov R4, 0      ; clear R4 (quotient)
mov R5, 0      ; clear R5 (remainder)

divide_loop:
  cmp ax, 12H   ; compare ax to 12H
  jl end_loop   ; if ax is less than 12H, jump to end_loop
  sub ax, 12H   ; subtract 12H from ax
  inc R4        ; increment R4 by 1
  jmp divide_loop  ; jump back to divide_loop

end_loop:
  mov R5, ax    ; store value in ax in R5 (remainder)
