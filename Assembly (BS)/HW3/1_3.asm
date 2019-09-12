.model small
.stack 100h
.data
A   db   '     This      is     a          test     $'
B   db   100 dup('$')
.code
mov ax,@data
mov ds,ax
mov cx,0
mov si,offset A
mov dx,0
mov dh,' '
mov dl,'$'
mov bx,offset B
again:
mov byte ptr ax,[si]
mov byte ptr [bx],ax 
inc si
inc bx
cmp [si],dl
jne again
.exit
end