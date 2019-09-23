.model  small
.stack   100h
.data
num1 db '-11h', 11b, 11h, -11
num2 dw 2 dup (-11, 2 dup (0f1c3h))
num3 dw 101b, num3
.code
	mov	ax,	@data
	mov	ds,	ax

	mov al , byte ptr num2-1
	mov bx, num3-2
.exit
end
