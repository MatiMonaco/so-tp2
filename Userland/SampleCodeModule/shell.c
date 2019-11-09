#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>
static void clearBuffer(char * buffer);


void initShell(){

	char command[COMMAND_MAX_LENGHT] ={0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		printf("$> ");
		char c;
		uint8_t i = 0;
		clearBuffer(command);
		scanf(command);
		putchar('\n');
		commandDispacher(command);
	}
		
}

static void commandDispacher(char* command){
	switch(command){
		
	}
}

static void clearBuffer(char * buffer){
	while(*buffer){
		*buffer = 0;
		buffer++;
	}
}
