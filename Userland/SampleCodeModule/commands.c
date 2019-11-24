#include <commands.h>
#include <exceptionsTest.h>
#include <stdio.h>
#include <aracnoid.h>
#include <callSysCall.h>
#include <libc.h>

static enum Registers{RAX = 0,RBX,RCX,RDX,RBP,RDI,RSI,R8,R9,R10,R11,R12,R13,R14,R15};

void infoReg(){
		printf("Registro RAX: ");
		printBin(getRegister(RAX));
		putchar('\n');

		printf("Registro RBX: ");
		printBin(getRegister(RBX));
		putchar('\n');

		printf("Registro RCX: ");
		printBin(getRegister(RCX));
		putchar('\n');

		printf("Registro RDX: ");
		printBin(getRegister(RDX));
		putchar('\n');

		printf("Registro RBP: ");
		printBin(getRegister(RBP));
		putchar('\n');

		printf("Registro RDI: ");
		printBin(getRegister(RDI));
		putchar('\n');

		printf("Registro RSI: ");
		printBin(getRegister(RSI));
		putchar('\n');

		printf("Registro R8: ");
		printBin(getRegister(R8));
		putchar('\n');

		printf("Registro R9: ");
		printBin(getRegister(R9));
		putchar('\n');

		printf("Registro R10: ");
		printBin(getRegister(R10));
		putchar('\n');

		printf("Registro R11: ");
		printBin(getRegister(R11));
		putchar('\n');

		printf("Registro R12: ");
		printBin(getRegister(R12));
		putchar('\n');

		printf("Registro R13: ");
		printBin(getRegister(R13));
		putchar('\n');

		printf("Registro R14: ");
		printBin(getRegister(R14));
		putchar('\n');

		printf("Registro R15: ");
		printBin(getRegister(R15));
		putchar('\n');
}

void printMem(char* address){
	if(*address == 0){
		perror("No address specified\n");
	}
	else{
    	uint64_t dir = atoi(address);
		printf("printmem:\n");
    	for(int i = 0; i < 32;i++,dir++){
    	    printf("byte %d : ", i+1);
    	    printMemASM(dir);
    	    putchar('\n');
    	}
	}
}

void time(){
    callSyscall(TIME,(void*) 0,(void*) 0,(void*) 0,(void*) 0,(void*) 0,(void*) 0);
    putchar('\n');
}

void aracnoid(){
	if(hasSavedGame()){

		char key;
		printf("Do you want to load your previous game? y/n");
		while((key = getchar()) != 'y' || key != 'n'){
			if(key == 'y'){
				load();
				break;
			}else if(key == 'n'){
				newGame();
				break;
			}
		}
	}else{
	
		newGame();
	}
	
}

void invalidopCodeException(){
	invalidOpCode();
}

void zeroDivException(){
	divisionByZero();
}

void clear(){
    callSyscall(CLEAR,(void*) 0,(void*) 0,(void*) 0,(void*) 0,(void*) 0,(void*) 0);
}
