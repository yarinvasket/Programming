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
jl any
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
printing:

mov al,[di]
cbw
	
	mov	bx,	10
	mov	si,	offset numS+5
	
	cmp ax,0
	jge next
	neg ax

next:	
	mov dx,0
	div	bx
	add	dl,	48
	mov	[si],dl
	dec	si
    cmp	ax,	0
	jne	next
	
	cmp	A[di],0
	jge	sof
	mov	byte ptr[si],	'-'
	dec si
	
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
	
		