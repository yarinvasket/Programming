.model  small
.stack   100h
.data
A db 232
.code
	mov	ax,	@data
	mov	ds,	ax

	push word ptr A
	call multi

	multi proc near
	push bp
	mov bp, sp
	mov bl, [bp+3]
	mov al, 1
	mov ah, 0
	mov cl, 10
	myLoop:
	cmp bl, 0
	je ext
	mul [bp+3]
	mov ah, 0
	xchg bx, ax
	div cl
	xchg bx, ax
	jmp myLoop
	ext:
	pop bp
	ret 1
	multi endp
.exit
end
