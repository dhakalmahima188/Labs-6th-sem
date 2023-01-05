; Replace the SWAP instruction using rotate right instructions
call swap_subroutine  ; call the swap subroutine

swap_subroutine:
  mov al, ah    ; move the contents of ah into al
  ror ax, 8     ; rotate ax right by 8 bits
  mov ah, al    ; move the contents of al into ah
  ret           ; return from subroutine

; Test the program on the contents of the accumulator when it contains the number 6BH
mov ah, 6BH    ; load 6BH into ah
call swap_subroutine  ; call the swap subroutine
; The contents of the accumulator should now be B6H (i.e. 6BH with the high and low bytes swapped)
