.model small
.stack 100h
.data
arr dw 17,3,2,-2,4
Sum dw 0
N equ 5
.code
mov ax,@data
mov ds,ax

mov bx,N
again:
mov ax,arr[bx]
add Sum,ax
dec bx
cmp bx,0
jne again


.exit 
end