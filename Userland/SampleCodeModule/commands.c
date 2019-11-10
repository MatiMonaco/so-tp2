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

void printMem(uint32_t address){
	printf("printmem:\n");
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