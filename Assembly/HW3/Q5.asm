.model small
.stack 100H
.data
numS db  6 dup(' '),'$'

A db 1,10,12,17,36
B db 0,2,4,5,16,65
c db 0

N1 equ 5
N2 equ 6
.code
	mov ax, @data
	mov ds, ax
	mov si, 0
	mov di, 0

	l00p:
	cmp si, N1
	jge N22
	cmp di, N2
	jge N11

	mov cl, A [si]
	cmp cl, B [di]
	jg greater
	jmp lesser

	greater:
	
	mov bx, si
	add bx, di
	mov cl, c [bx]
	mov cl, B [di]
	inc di
	jmp l00p

	lesser:
	mov bx, si
	add bx, di
	mov cl, A [si]
	mov c [bx], cl
        inc si
	jmp l00p

	N11:
	cmp si, N1
	jge print
	mov bx, si
	add bx, di
	mov cl, A [si]
	mov c [bx], cl
	inc si
	jmp N11

	N22:
	cmp di, N1
        jge print
	mov bx, si
	add bx, di
	mov cl, B [di]
        mov c [bx], cl
        inc di
        jmp N22

	print:
	mov si, 0
	mov di, 0

	printLoop1:
	mov ax, di
	mov dx, N1
	add dx, N2
	cmp ax, dx
	jge ending
	mov ah, 02h
	mov dl, ' '
	int 21h

	printLoop2:
	mov	ax,	word ptr c [di]
	mov ah, 0
	mov	bx,	10
	mov	si,	offset numS+5

next:	
	mov dx,0
	div	bx
	add	dl,	30h
	mov	[si],	dl
	dec	si
    cmp	ax,	0
	jne	next
	
sof:
	inc si
	mov	ah,	9
	mov	dx,	si
	int	21h
inc di
jmp printLoop1
	
ending:
	.exit
end
