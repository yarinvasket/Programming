.model  small
.stack   100h
.data
A dw 12, 5, 8, -1, 4
B dw -2, 9, 0, 18, 3
C dw 5 dup (?)
N equ 5
.code
	mov	ax,	@data
	mov	ds,	ax

	push offset A
	push offset B
	push offset C
	push N
	call sum
	.exit

	sum proc near
	push bp
	mov bp, sp
	mov si, 0
	myloop:
	cmp si, [bp+4]
	je ext

	mov bx, [bp+10]
	mov ax, [bx+si]
	mov bx, [bp+8]
	add ax, [bx+si]
	mov bx, [bp+6]
	mov [bx+si], ax
	inc si
	jmp myLoop
	ext:
	pop bp
	ret 8
	sum endp
end
