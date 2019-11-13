GLOBAL cpuVendor
section .text

cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

_beep_start:
	push rbp
	mov rbp, rsp

	mov al, 0xB6
	out 43h,al

	mov rbx, rdi
	mov rax, 0
	mov ax, bx

	;mov ax, 1193 ;1193180 / nFrequence;
	out 42h,al
	mov al,ah
	out 42h,al

	in al, 61h 
 	or al, 03h
	out 61h,al

	mov rsp, rbp
	pop rbp
	ret

_beep_stop:
  	in al, 61h
	and al, 0xFC
	out 61h, al
  	ret
