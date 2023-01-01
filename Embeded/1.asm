; Add the numbers 897F9AH and 34BC48H and save the result in internal RAM starting at 40H
mov ax, 897F9AH  ; load 897F9AH into ax
add ax, 34BC48H  ; add 34BC48H to ax
mov bx, 40H      ; load 40H into bx (starting address for RAM)
mov [bx], ax     ; store value in ax at memory location pointed to by bx

; Display the result continuously on the LEDs of the development board
mov bx, 40H      ; load 40H into bx (starting address for RAM)

display_loop:
  mov al, [bx]   ; load value at memory location pointed to by bx into al
  out P0, al      ; output value in al to port P0 (LEDs)
  add bx, 1       ; increment bx by 1
  jmp display_loop  ; jump back to display_loop
