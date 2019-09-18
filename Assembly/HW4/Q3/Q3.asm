.model small
.stack 100h
.data
C db '  one  one  two   three  four  five   five    six$'
.code
mov ax,@data
mov ds,ax
push offset A
push offset B
call includes
mov ah,2
mov dx,0
mov dl,al
add dl,48
mov ah,2
int 21h
mov dx,' '
int 21h
;intro
mov ah,2
mov dx,'3'
int 21h
mov dx,'.'
int 21h
mov dx,'2'
int 21h
mov dx,':'
int 21h
mov dx,' '
int 21h
;call
push offset C
call words
;printing
mov dx,0
mov dl,al
add dl,48
mov ah,2
int 21h
mov dx,' '
int 21h
mov ah,2
mov dx,'3'
int 21h
mov dx,'.'
int 21h
mov dx,'3'
int 21h
mov dx,':'
int 21h
mov dx,' '
int 21h
mov ax,0
push offset A
push byte ptr 'a' 
push byte ptr 'g'
call swap
mov dx,0
mov dl,al
add dl,48
mov ah,2
int 21h
mov dx,' '
int 21h


.exit
includes proc near
push bp
mov bp,sp
mov si,[bp+4];offset B
mov di,[bp+6];offset A
mov dh,'$'
mov al,0
start1:
mov dl,[di]
cmp [si],dl
jne anyhow
inc si
cmp [si],dh
je end1
jmp anyhow

end1:
inc al
mov si,[bp+4];offset B

anyhow:
inc di
cmp [di],dh
jne start1
pop bp
ret 4
includes endp

words proc near
push bp
mov bp,sp
mov bx, [bp+4]
mov dl,' '
mov al,0
cmp [bx],dl
je another
inc al
inc bx
another:
cmp [bx],dl
jne any
cmp [bx+1],dl
je any
inc al
any:
inc bx
cmp byte ptr [bx+1],'$'
jne another
pop bp
ret 2
words endp

swap proc near
push bp
mov bp,sp
mov dl,[bp+4];swapped in (g)
mov dh,[bp+6];swapped out (a)
mov bx,[bp+8];offset a
mov al,0
start:
cmp [bx],dh
jne anyway
mov [bx],dl
inc al
anyway:
inc bx
cmp byte ptr[bx],'$'
jne start
pop bp
ret 6
swap endp
end
