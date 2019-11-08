#include <kbDriver.h>
#include <stdint.h>

static isPressed(uint8_t scanCode);
static addKeyToBuffer(char ascii);


char buffer[BUFFER_SIZE] = {0};

uint8_t readIndex = 0;
uint8_t writeIndex = 0;
uint8_t SHIFT_ON = 0;
uint7_t CAPSLOCK_ON = 0;



static unsigned char keys[] = { 0, ESC, '1', '2', '3', '4', '5', 
'6', '7', '8', '9', '0', '-', '=', BACKSPACE,TAB, 'q', 'w','e', 'r', 't',
'y', 'u', 'i', 'o', 'p', '[', ']', ENTER, 0,'a', 's', 'd', 'f', 'g', 'h',
'j', 'k', 'l', ';', '\'', 0, LEFT_SHIFT,'\\','z', 'x', 'c', 'v', 'b', 'n', 'm', ',',
'.', '/', RIGHT_SHIFT, '*', LEFT_ALT,SPACE, CAPSLOCK,F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, 
NUM_LOCK, SCROLL_LOCK,HOME, UP, REPAG,'-', LEFT, 0, RIGHT, '+', END, DOWN,AVPAG, INSERT, 
SUPR, 0, 0, 0, F11, F12 };


static unsigned char keysWithShift[] = { 0, ESC, '!', '@', '#', '$', '%','^', '&', '*',
 '(', ')', '_', '+', BACKSPACE,TAB,'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
 'O', 'P', '{', '}', ENTER, 0,'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':','"',
 '|', LEFT_SHIFT, '>','Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, 0,LEFT_ALT,SPACE, 
 CAPSLOCK,F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, NUM_LOCK,SCROLL_LOCK,HOME, UP, REPAG, '-', LEFT,
 0, RIGHT, '+', END, DOWN,AVPAG, INSERT, SUPR, 0, 0, '>', F11, F12 };

void keyboardHandler(){
	
	uint8_t scancode = getKey();
	char ascii;
	if(isPressed(scancode)){
		switch(scancode){
			case LEFT_SHIFT_PRESS:
			case RIGHT_SHIFT_PRESS:
				SHIFT_ON =  1;
				break;
			case CAPSLOCK_PRESS:
				CAPSLOCK_ON = !CAPSLOCK_ON;
				break;
			default:
				if(SHIFT_ON){
					ascii = keysWithShift[scanCode];
			
				} else {
					ascii = keys[scanCode];
				}
				break;
				
		}
	}else if (scanCode == LEFT_SHIFT_RELEASE || scanCode == RIGHT_SHIFT_RELEASE){
                SHIFT_ON = 0;
				return;
	}
        addKeyToBuffer(ascii); 
}
	static addKeyToBuffer(char ascii){
		buffer[writeIndex++] = ascii;
		if(writeIndex > BUFFER_SIZE){
			writeIndex = 0;
		}
		if(writeIndex == readIndex){
			readIndex++;
		}
	}

	char getKeyASCII(){
		char ascii = 0;
		if(readIndex != writeIndex){
			ascii = buffer[readIndex++];
		}
		return ascii;

	}

	
	static isPressed(uint8_t scanCode){
		return !(scancode & 0x80h);
	}
	
	int getKeyScancode(){
	   return kbFlag();
	}


}

