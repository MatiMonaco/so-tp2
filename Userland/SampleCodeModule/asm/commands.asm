GLOBAL printRegisters
GLOBAL printMemASM
EXTERN printBin
section .txt:

infoReg:
		push rbp
		mov rbp,rsp



		mov rsp,rbp
		pop rbp
		ret


printMemASM:
	push rbp
	mov rbp,rsp
	mov al,byte[rdi]
	

