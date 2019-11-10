#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

struct commandStruct{
	uint64_t id;
	char name[25];
	char* desc[50];
	
};
#define HELP 0
#define EXIT 1
#define TIME 2
#define PRINTMEM 3
#define INFOREG 4
#define ARACNOID 5
#define OPCODEEX 6
#define ZERODIVEX 7


#define COMMAND_MAX_LENGHT 100

void printMem(uint64_t address);
void infoReg();
void time();
void aracnoid();
void exit();
void zeroDivException();
void invalidopCodeException();
uint64_t getRegister(uint64_t reg);

#endif