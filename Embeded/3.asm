; Multiply the data in RAM location 22H by the data in RAM location 15H
mov ax, [22H]   ; load value at RAM location 22H into ax
mov bx, [15H]   ; load value at RAM location 15H into bx
mov cx, 0       ; clear cx (counter)
mov dx, 0       ; clear dx (high byte of result)

multiply_loop:
  add dx, ax     ; add ax to dx
  inc cx         ; increment cx by 1
  cmp cx, bx     ; compare cx to bx
  jne multiply_loop  ; if cx is not equal to bx, jump back to multiply_loop

; Store result in RAM locations 19H (low byte) and 1AH (high byte)
mov [19H], dx   ; store low byte of result in RAM location 19H
mov [1AH], ax   ; store high byte of result in RAM location 1AH
