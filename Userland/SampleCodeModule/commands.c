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
	printf("inforeg:\n");
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