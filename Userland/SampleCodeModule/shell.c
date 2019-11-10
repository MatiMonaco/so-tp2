#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>

static void clearBuffer(char * buffer);
static void commandDispacher(char* command);
static void commandNotFound();
static int64_t getCommandId(char * command);
static void help();

static struct commandStruct commands[] = {{EXIT,"exit","Exits shell"},
										{TIME,"time","Displays current time"},
										{PRINTMEM,"printmem address","Performs a 32-byte memory dump from the address received as an argument"},
										{INFOREG,"inforeg","Prints the value of all the registers"},
										{ARACNOID,"aracnoid","Iniciates aracnoid, press 'space' to leave"},
										{OPCODEEX,"opcodeex","Executes Invalid OP Code Interruption"},
										{ZERODIVEX,"zerodivex","Executes Zero Division Interruption"},
										{0,"",""}};

void initShell(){

	char command[COMMAND_MAX_LENGHT] ={0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		printf("$> ");
		clearBuffer(command);
		scanf("%s",command);
		putchar('\n');
		commandDispacher(command);
	}
		
}

static void commandDispacher(char* command){
	
	uint64_t id = getCommandId(command);
	switch(id){

		case HELP:
			help();
		break;

		case EXIT:
			exit();
		break;

		case TIME:
			time();
		break;

		case PRINTMEM:
			
		break;

		case INFOREG:
			infoReg();
		break;

		case ARACNOID:
			aracnoid();
		break;

		case OPCODEEX:
			invalidopCodeException();
		break;

		case ZERODIVEX:
			divisionByZero();
		break;

		default:
		commandNotFound();
		break;
		
		
	}
	
	
}

static int64_t getCommandId(char * command){
	
	for(int i = 0; strcmp(commands[i].name,"") != 0;i++){
		if(strcmp(commands[i].name,command) == 0){
			return commands[i].id;

		}
	}
	return -1;
	
}	

static void help(){
	printf("\n\n********  Help Menu  ********\n\n");
  printf("  * clear     :       Clears screen\n");
  printf("  * opcodeex :       Executes Invalid OP Code Interruption\n");
  printf("  * zerodivex   :       Executes Zero Division Interruption\n");
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
