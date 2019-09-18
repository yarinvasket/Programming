.model  small
.stack   100h
.data
num  dw  65535
numS db  6 dup(' '),'$'

.code
	mov	ax,	@data
	mov	ds,	ax

	mov	ax,	num
	mov	bx,	10
	mov	si,	offset numS+5
	
	cmp ax,0
	jae next
	neg ax

next:	
	mov dx,0
	div	bx
	add	dl,	48
	mov	[si],	dl
	dec	si
    cmp	ax,	0
	jne	next
	
	cmp	num,0
	jae	sof
	mov	byte ptr[si],	'-'
	dec si
	
sof:
	inc si
	mov	ah,	9
	mov	dx,	si
	int	21h
	.exit
end