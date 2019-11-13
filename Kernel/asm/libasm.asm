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
beepon:
    push rbp
    mov rbp, rsp

    mov al, 0xB6
    out 0x43, al
    ;Convert the frequency into two eight bit values, then output them to port 42h
    mov rax, 0
    mov ax, 3A98h       
    out 0x42, al
    mov al, ah
    out 0x42, al
    in al, 0x61
    mov al, 0x03 ;prendo el speaker
    out 61h, al

    mov rsp, rbp
    pop rbp
    ret
    
beepoff:
    in al, 61h
    mov al, 0x00 ;apago el speaker
    out 61h, al
    ret
