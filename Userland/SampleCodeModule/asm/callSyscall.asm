GLOBAL callSyscall
section .text

callSyscall:
    push rbp
    mov rbp,rsp
    
    int 80h

    mov rsp,rbp
    pop rbp
    ret
    
    
getAllRegisters:
	mov rax, 5
	int 80h

	ret
