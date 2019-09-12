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
start:
cmp [si+1],dh
jne gam
cmp [si],dh
je gam
inc cx
gam:
inc si
cmp [si],dl
jne start
.exit 
end