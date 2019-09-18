.model small
.stack 100h 
.data
A   db   '     This      is     a          test     $'
B   db   100 dup('$')
.code
mov ax,@data
mov ds,ax
mov si,offset A
mov word ptr cx,0
mov bx, 0
mov dh,' '
mov dl,'$'
first:
cmp [si],dh
jne next
inc cx
next:
inc si 
cmp [si],dl
jne first








.exit
end