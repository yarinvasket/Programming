.model  small
.stack   100h
.data
A dw -35
B dw 43
.code
	mov	ax,	@data
	mov	ds,	ax

	push A
	push B
	call sum
	.exit

	sum proc near
	push bp
	mov bp, sp
	mov ax, [bp+4]
	add ax, [bp+6]
	pop bp
	ret 4
	sum endp
end
