#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>
static void clearBuffer(char * buffer);
static void commandDispacher(char* command);
static void commandNotFound();

static struct commandStruct commands[] = {{"help",&help},{"inforeg",&inforeg},{"printmem",&printmem},{"aracnoid",&aracnoid},{0,0}};

void initShell(){

	char command[COMMAND_MAX_LENGHT] ={0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		printf("$> ");
		clearBuffer(command);
		scanf(command);
		putchar('\n');
		commandDispacher(command);
	}
		
}

static void commandDispacher(char* command){
	for(int i = 0; commands[i].name != 0; i++){
		if(strcmp(commands[i].name,command) == 0){
			*(commands[i].f);
		}
	}
	
}


static void commandNotFound(){
	perror("shell: command not found\n");
}

static void clearBuffer(char * buffer){
	while(*buffer){
		*buffer = 0;
		buffer++;
	}
}
