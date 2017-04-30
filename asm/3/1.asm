assume cs:codesg

data segment
	db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
	db '1984','1985','1986','1987','1988','1989','1990','1901','1992'
	db '1993','1994','1995'

	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
	dw 11542,14430,15257,17800
data ends

table segment
	db 21 dup ('year sumn ne ?? ')
table ends

codesg segment
start:  mov cx, 21
	mov bx, 0
	mov bp, 0
	mov dx, 0
	mov ax, data
	mov ds, ax
	mov ax, table
	mov ss, ax
	mov si, 0

for1:	mov di, 0
	mov dx, cx
	mov cx, 4
for2:	mov al, [bx+si]
	mov [bp+di], al
	inc si
	inc di
	loop for2
	
	add bp, 16
	mov cx, dx
	loop for1

	mov cx, 21
	mov bp, 0
for3:	mov di, 5
	mov ax, [bx+si]
	mov [bp+di], ax
	add si, 2
	add di, 2
	mov ax, [bx+si]
	mov [bp+di], ax
	add si, 2
	add di, 2
	add bp, 16
	loop for3	

	mov cx, 21
	mov bp, 0
for4:	mov di, 10
	mov ax, [bx+si]
	mov [bp+di], ax
	add si, 2
	add di, 2
	add bp, 16
	loop for4


	mov cx, 21
	mov bp, 0
for5:	mov ax, [bp+5]
	mov dx, [bp+7]
	mov bx, [bp+10]
	div bx
	mov [bp+13], ax
	add bp, 16
	loop for5

	mov ax, 4c00h
	int 21h
codesg ends
end start
