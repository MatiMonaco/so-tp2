#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>

static void clearBuffer(char * buffer);
static void commandDispacher(char* command);
static void commandNotFound();
static void help();
struct commandStruct commands[] = {{"help",&help},{"inforeg",&inforeg},{"printmem",&printmem},{"aracnoid",&aracnoid},{"time",&time},{0,0}};


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
			commands[i].f();
			return;
		}
	}
	commandNotFound();
	
}

static void help(){
	printf("\n\n********  Help Menu  ********\n\n");
  printf("  * clear     :       Clears screen\n");
  printf("  * invopcode :       Executes Invalid OP Code Interruption\n");
  printf("  * zerodiv   :       Executes Zero Division Interruption\n");
  printf("  * exit      :       Exits shell\n");
  printf("  * time      :       Displays current time\n");
  printf("  * aracnoid  :       Iniciates aracnoid, press 'space' to leave\n");
  printf("  * printmem address  :       Performs a 32-byte memory dump from the address received as an argument\n");
  printf("  * inforeg   :       Prints the value of all the registers\n");

  printf("\n  Any other command will be taken as invalid\n\n");
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
