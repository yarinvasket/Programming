.model  small
.stack   100h
.data
A dw 12, 5, 8, -1, 4
B dw -2, 9, 0, 18, 3
C dw 5 dup (?)
D dw 5
.code
	mov	ax,	@data
	mov	ds,	ax

	push offset A
	push offset B
	push offset C
	push D
	call sum
	.exit

	sum proc near
	push bp
	mov bp, sp
	mov si, 0
	myloop:
	cmp si, [bp+10]
	jge exit
	mov ax, [bp+4+si]
	add ax, [bp+6+si]
	mov [bp+8+si], ax
	inc si
	jmp myLoop
	exit:
	pop bp
	ret 8
	sum endp
end
