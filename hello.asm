section .data
hello:     db 'Hello world!',10    ; 'Hello world!' plus a linefeed character
helloLen:  equ $-hello             ; Length of the 'Hello world!' string
array:     db 1, 2, 3, 4
ans dw 0

section .text
global _start

_start:
	mov ax, 0
	mov bl, 0
	mov ch, 0
	loopstart:
		mov cx,array[1]
		add ax, cx
		inc bl
		cmp bl, 4
		jl loopstart

	add ax, 48
	mov [ans] , ax
	mov ecx ,ans
	mov eax, 4
	mov ebx, 1
	mov edx,1 
	int 80h

	mov eax,1            ; The system call for exit (sys_exit)
	mov ebx,0            ; Exit with return code of 0 (no error)
	int 80h
