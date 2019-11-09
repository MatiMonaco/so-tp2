#ifndef COMMANDS_H
#define COMMANDS_H
#define COMMAND_MAX_LENGHT 100


struct commandStruct{
	char * name;
	void (*f) (void);
};


void inforeg();
void help();
void printmem();
void time();
void aracnoid();


#endif