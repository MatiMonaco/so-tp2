GLOBAL invalid_op_code
GLOBAL division_by_zero

divisionByZero:
	mov rdx, 5
	mov al,1
	mov bl,0
	div bl
	ret

invalidOpCode:
	OwO
	ret