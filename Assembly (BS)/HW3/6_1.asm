.model small
.stack 100h
.data
arr db 17,3,2,-2,4
Sum db 0
N equ 5
.code
mov ax,@data
mov ds,ax

mov bx,N
again:
mov cl,arr[bx]
add Sum,cl
dec bx
cmp bx,0
jne again


.exit 
end