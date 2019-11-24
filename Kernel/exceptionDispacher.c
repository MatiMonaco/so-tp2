#include <stdout.h>
#include <lib.h>
#define ZERO_EXCEPTION_ID 0
#define INVALID_CODE_ID 6

//static void zero_division(uint64_t * instructionPointer, uint64_t * stackPointer);
//static void invalid_opcode(uint64_t * instructionPointer, uint64_t * stackPointer);
static void printRegisters(uint64_t * instructionPointer, uint64_t * stackPointer);

//typedef void (*exception_ptr)(uint64_t * instructionPointer, uint64_t * stackPointer);

//exception_ptr exceptions[] = {zero_division,0,0,0,0,0,invalid_opcode};

void exceptionDispatcher(int exception_id,uint64_t * instructionPointer, uint64_t * stackPointer){
	//exceptions[exception_id](instructionPointer,stackPointer);
	switch(exception_id)
	{
		case ZERO_EXCEPTION_ID: 
				drawStringWithColor("ZERO EXCEPTION",0xff0000,0x000000);
				drawChar('\n',0xffffff,0x000000);
            break;
	    case INVALID_CODE_ID: 
				drawStringWithColor("INVALID OPERATION CODE",0xff0000,0x000000);
				drawChar('\n',0xffffff,0x000000);
		    break;
	}
	printRegisters(instructionPointer,stackPointer);
}

void printRegisters(uint64_t * instructionPointer, uint64_t * stackPointer){
	char* registers[] = {"R15","R14","R13","R12","R11","R10","R9","R8","RSI","RDI","RBP","RDX","RCX","RBX","RAX"};
	char IP[65];
	intToBase(*instructionPointer,IP,2);
	drawString("instruction Pointer: ");
	drawString(IP);
	drawChar('\n',0xffffff,0x000000);
	char reg[65];
	for(int i = 14; i >= 0; i--){
		drawString(registers[i]);
		drawString(" : ");
		intToBase(*(stackPointer + i),reg,2);
		drawString(reg);
		drawChar('\n',0xffffff,0x000000);
	}
}

/*
void zero_division(uint64_t * instructionPointer, uint64_t * stackPointer){
	drawStringWithColor("ZERO EXCEPTION",0xff0000,0x000000);
	printRegisters()
}

void invalid_opcode(uint64_t * instructionPointer, uint64_t * stackPointer){
}
*/
