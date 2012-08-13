section .data
array: db 0,1,2,3,4,5,6,7,8 
message: db 'Hello World'
msglength: equ 12
buffersize: dw 1024

section .bss
filename: resb 255
number: resb 1
bignum: resw 1
realarray: resq 10

section .text
global _start

_start:
mov eax, 4
mov ebx, 1
mov ecx, array+ 1
mov edx, 1
int 80h

mov eax, 1
mov ebx, 0
int 80h
