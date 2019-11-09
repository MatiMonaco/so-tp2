#include <shell.h>
#include <stdio.h>
#include <string.h>
static void clearBuffer(char * buffer);
static uint8_t inforeg();

void initShell(){

	char command[COMMAND_MAX_LENGHT] ={0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		printf("$> ");
		char c;
		uint8_t i = 0;
		clearBuffer(command);
		while((c = getchar()) != '\n'){
			command[i++] = c;
			putchar(c);
		}
		printf(command);
	}
		
}

static void clearBuffer(char * buffer){
	while(*buffer){
		*buffer = 0;
		buffer++;
	}
}
static uint8_t inforeg(){
    getAllRegisters();
    return 0;
}
