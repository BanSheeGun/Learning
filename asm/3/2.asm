DSEG SEGMENT
    grade    dw   88,75,95,63,98,78,87,78,90,60
    rank     dw   10 dup (?)
DSEG ENDS
CSEG SEGMENT
assume  cs:CSEG, ds:DSEG
start:	mov ax, dseg
	mov ds, ax
	mov di,10
	mov bx,0
loop:	mov ax, [bx]
	mov dx,1
	mov cx,10
	mov si, 0
next: 	cmp ax,[si]
	jge no_count
	inc dx
no_count:add si,2
	loop next

        mov [bx+20], dx
	add bx,2
        cmp bx, 20
	jne loop

	mov ax, 4c00h 
	int 21h
   
CSEG ENDS
end start
