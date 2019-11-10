GLOBAL printRegisters

EXTERN printBin

section .txt:

infoReg:
		push rbp
		mov rbp,rsp



		mov rsp,rbp
		pop rbp
		ret
		

