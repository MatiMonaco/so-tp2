GLOBAL getCurrSecs
GLOBAL getCurrMins
GLOBAL getCurrHs
GLOBAL initRTC
section .text


initRTC:
	push rbp
	mov rbp,rsp

	mov al,0x0b
	out 70h,al
	mov al,0x06
	out 71h,al
	mov rsp,rbp
	pop rbp
	ret

getCurrSecs:
	push rbp
	mov rbp, rsp

	mov al, 0x00
	out 70h, al
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret

getCurrMins:
	push rbp
	mov rbp, rsp

	mov al, 0x02
	out 70h, al
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret

getCurrHs:
	push rbp
	mov rbp, rsp

	mov al, 0x04
	out 70h, al
	in al, 71h

	mov rsp, rbp
	pop rbp
	ret