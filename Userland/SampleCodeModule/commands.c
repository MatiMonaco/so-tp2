#include <commands.h>
#include <exceptionsTest.h>
#include <stdio.h>

/*
void  inforeg(){
    getAllRegisters();
    return 0;
}
*/



void infoReg(){
		printf("Registro RAX: ");
		printBin(getRegister(RAX));
		putchar('\n');

		printf("Registro RBX: ");
		printBin(getRegister(RBX));
		putchar('\n');

		printf("Registro RCX: ");
		printBin(getRegister(RCX));
		putchar('\n');

		printf("Registro RDX: ");
		printBin(getRegister(RDX));
		putchar('\n');

		printf("Registro RBP: ");
		drawBin(getRegister(RBP));
		putchar('\n');

		printf("Registro RDI: ");
		printBin(getRegister(RDI));
		putchar('\n');

		printf("Registro RSI: ");
		printBin(getRegister(RSI));
		putchar('\n');

		printf("Registro R8: ");
		printBin(getRegister(R8));
		putchar('\n');

		printf("Registro R9: ");
		printBin(getRegister(R9));
		putchar('\n');

		printf("Registro R10: ");
		printBin(getRegister(R10));
		putchar('\n');

		printf("Registro R11: ");
		printBin(getRegister(R11));
		putchar('\n');

		printf("Registro R12: ");
		printBin(getRegister(R12));
		putchar('\n');

		printf("Registro R13: ");
		printBin(getRegister(R13));
		putchar('\n');

		printf("Registro R14: ");
		printBin(getRegister(R14));
		putchar('\n');

		printf("Registro R15: ");
		printBin(Register(R15));
		putchar('\n');
}

void printMem(uint64_t* address){
	printf("printmem:\n");
    for(int i = 0; i < 32;i++){
        printf("byte %d : ", i+1);
        printMenASM(*address++);
        putchar('\n');
    }
}
void time(){
	printf("time:\n");
}
void aracnoid(){
	printf("aracnoid:\n");
}

void invalidopCodeException(){
	invalidOpCode();
}

void zeroDivException(){
	divisionByZero();
}
void exit(){
}