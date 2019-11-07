GLOBAL getCurrSecs
GLOBAL getCurrMins
GLOBAL getCurrHs

section .text

getCurrSecs:
	push rbp
	mov rbp, rsp

	mov al, 0
	out 70h, al
	in ax, 71h

	mov rsp, rbp
	pop rbp
	ret

getCurrMins:
	push rbp
	mov rbp, rsp

	mov al, 2
	out 70h, al
	in ax, 71h

	mov rsp, rbp
	pop rbp
	ret

getCurrHs:
	push rbp
	mov rbp, rsp

	mov al, 4
	out 70h, al
	in ax, 71h

	mov rsp, rbp
	pop rbp
	ret