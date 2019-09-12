.model  small
.stack   100h
.data
A  db  17,2,-13,48,36
numS db  6 dup(' '),'$'
N equ 5

.code
;for every proc
;push bp
;mov bp,sp
	mov	ax,	@data
	mov	ds,	ax
	
    mov si, offset A
	
	again:
	mov cl,[si]
	mov ch,[si+1]
	
cmp cl,ch
jb any
mov bl,cl
mov bh,ch
mov [si],bh
mov [si+1],bl

any:
inc si
mov al,N
add al,offset A-1
cbw
cmp si,ax
jl again










;printing
mov di,offset A
mov bx,0
printing:

mov al,[di]

	
	mov	bl,	10
	mov	si,	offset numS+5

next:	
	mov ah,0
	div	bl
	add	ah,	48
	mov	[si],ah
	dec	si
    cmp	al,	0
	jne	next
	
	
	
sof:
	inc si
	mov	ah,	9
	mov	dx,	si
	int	21h
	mov ah,2
	mov dx,' '
	int 21h
	inc di
	mov cx,N
	add cx, offset A
	cmp di,cx
	jne printing
	.exit
end
	
		