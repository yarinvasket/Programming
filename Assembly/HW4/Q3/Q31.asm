.model  small
.stack   100h
.data
A db 'something somewhere$'
B db 'some$'
.code
	mov	ax,	@data
	mov	ds,	ax

	push offset A
	push offset B
	foo proc near
	push bp
	mov bp, sp
	mov al, 0
	mov si, 0
	mov di, 0
	myLoop:
	mov bx, [bp+4]
	cmp [bx+si], '$'
	je ext
	next:
	mov bx, [bp+6]
	cmp [bx+di], '$'
	je insi
	mov dl, [bx+di]
	mov bx, [bp+4]
	cmp dl, [bx+si]
	je sof
	jmp insi
	insi:
	inc si
	mov di, 0
	jmp myLoop
	sof:
	inc di
	mov bx, [bp+6]
	cmp [bx+di], '$'
	je incal
	mov dl, [bx+di]
	mov bx, [bp+4]
	cmp dl, [bx+si]
	je sof
	jmp incsi
	incal:
	inc al
	jmp incsi
	ext:
	pop bp
	ret 4
	foo endp
	.exit
end
