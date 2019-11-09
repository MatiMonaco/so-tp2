#ifndef COMMANDS_H
#define COMMANDS_H
#define COMMAND_MAX_LENGHT 100


typedef   void (*Commandf) (void);

struct commandStruct{
	char * name;
	Commandf f;
};


void inforeg();
void help();
void printmem();
void time();
void aracnoid();


#endif