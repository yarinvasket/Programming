.model  small
.stack   100h
.data
A dw 12, 5, 8, -1, 4
B dw -2, 9, 0, 18, 3
C dw 5 dup (?)
.code
	mov	ax,	@data
	mov	ds,	ax

	push offset A
	push offset B
	push offset C
	push 5
	call sum
	.exit

	sum proc near
	push bp
	mov bp, sp
	mov si, 0
	myloop:
	cmp si, [bp+11]
	jge ext

	mov bx, [bp+4]
	mov ax, [bx+si]
	mov bx, [bp+6]
	add ax, [bx+si]
	mov bx, [bp+8]
	mov [bx+si], ax
	inc si
	jmp myLoop
	ext:
	pop bp
	ret 8
	sum endp
end
