#include <screenDriver.h>
#define ZERO_EXCEPTION_ID 0
#define INVALID_CODE_ID 6

void exceptionDispatcher(int exception_id){
switch(exception_id)
	{
		case ZERO_EXCEPTION_ID: 
		    drawChar('Z',0xFFFFFF,0x000000);
                    break;
	        case INVALID_CODE_ID: 
	            drawString("INVALID OPERATION EXCEPTION");
		    break;
	}
	//printRegisters();
}




/*
static void zero_division();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
}

static void zero_division() {
	// Handler para manejar excepcíon
}

*/
