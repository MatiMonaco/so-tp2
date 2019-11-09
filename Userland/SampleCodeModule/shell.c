#include <shell.h>
#include <stdio.h>
#include <string.h>
static void clearBuffer(char * buffer);
static int inforeg();

void initShell(){

	char command[COMMAND_MAX_LENGHT] ={0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		 printf("$> ");
		 char c;
		 int i = 0;
		// clearBuffer(command);
		 while((c = getchar()) != '\n'){
			command[i] = c;
			putchar(command[i]);
			putchar(' ');
			putchar(command[i-1]);
			i++;
		 }
		for(int j = 0; j < 10; j++){
			putchar(command[j]);
		}

		//printf("mensaje\n");


		//printf(command);*/
	//	scanf(command);
	}
		
	
}

static void clearBuffer(char * buffer){
	while(*buffer){
		*buffer = 0;
		buffer++;
	}
	
static int inforeg(){
    getAllRegisters();
    return 0;
}
}
