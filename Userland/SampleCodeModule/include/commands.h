#ifndef COMMANDS_H
#define COMMANDS_H
#define COMMAND_MAX_LENGHT 100
#include <stdint.h>

typedef   void (*Commandf) (va_list args);

struct commandStruct{
	char * name;
	Commandf f;
};


void inforeg(uint8_t cant_args,...);

void printmem(uint8_t cant_args,...);
void time(uint8_t cant_args,...);
void aracnoid(uint8_t cant_args,...);


#endif