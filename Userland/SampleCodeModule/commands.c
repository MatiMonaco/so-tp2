#include <commands.h>
#include <exceptionsTest.h>
#include <stdio.h>

/*
void  inforeg(){
    getAllRegisters();
    return 0;
}
*/


void inforeg(){
	printf("inforeg:\n");
}

void printmem(uint32_t address){
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