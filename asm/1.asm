DSEG SEGMENT
grade    dw   56,69,84,82,73,88,99,63,100,80
s5       dw   0
s6       dw   0
s7       dw   0
s8       dw   0
s9       dw   0
s10      dw   0
DSEG ENDS
CSEG SEGMENT
	assume  cs:CSEG, ds:DSEG
start:	mov ax, dseg
	mov ds, ax
	mov cx, 10
	mov bx, offset grade
compare:mov ax, [bx]
	cmp ax, 60
	jl five
	cmp ax, 70
	jl six
	cmp ax, 80
	jl seven
	cmp ax, 90
	jl eight
	cmp ax, 100
	jne nine
        inc s10
        jmp short change_addr
nine:	inc s9
	jmp short change_addr
eight:	inc s8
	jmp short change_addr
seven:	inc s7
	jmp short change_addr
six:	inc s6
	jmp short change_addr
five:	inc s5
change_addr:
        add bx, 2
        loop compare       
	mov ax, 4c00h 
	int 21h
CSEG ENDS
end start
