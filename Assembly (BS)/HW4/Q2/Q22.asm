.model  small
.stack   100h
.data
A dw 12, 5, 8, -1, 4
B dw -2, 9, 0, 18, 3
C dw 5 dup (3)
.code
	mov	ax,	@data
	mov	ds,	ax

	push offset A
	push offset B
	push offset C
	push 5
	call sum
	.exit
end
