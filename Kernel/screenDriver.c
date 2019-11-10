#include <video_vm.h>
#include <screenDriver.h>
#include <font.h>
#include <lib.h>

unsigned int x = 0;
unsigned int y = 0;

static void scrollDown();
char* intToBase(int num, char* str, int base);
void reverse(char str[], int length);
void drawDec(uint64_t value);
void drawHexa(uint64_t value);
void drawBin(uint64_t value);
void drawBase(uint64_t value, uint32_t base);

void drawChar(char character, int fontColor, int backgroundColor){
    if(x == getScreenWidth()){
        if(y == getScreenHeight()){
            scrollDown();
        }
        else{
            y += CHAR_HEIGHT;
        }
		x = 0;
    }
	if(character == '\n'){
		newline();
	}
	else if(character == '\b'){
		deleteChar();
	}
	else{
    	drawCharAt(x,y,character,fontColor,backgroundColor);
		x += CHAR_WIDTH;
	}
}

void newline(){
	if(y == getScreenHeight()){
		scrollDown();
	}
	else{
		y += CHAR_HEIGHT;
	}
	x = 0;
}

void deleteChar(){
	if(y != 0 || x != 0){
		if(x == 0){
			x = getScreenWidth();
			y -= CHAR_HEIGHT;
			drawCharAt(x,y,' ',0xFFFFFF,0x000000);
		}
		else{
			x -= CHAR_WIDTH;
			drawCharAt(x,y,' ',0xFFFFFF,0x000000);
		}
	}
}

void drawString(const char *string){
	while(*string != '\0'){
		drawChar(*string,0xFFFFFF,0x000000);
		string++;
	}
}

void drawStringWithColor(const char *string, int fontColor, int backgroundColor){
	while(*string != '\0'){
		drawChar(*string,fontColor,backgroundColor);
		string++;
	}
}

void scrollDown(){
	char* start = getFrameBuffer();
	char * secondLine = start + (getScreenWidth() * getScreenBPP());
	int size = getScreenWidth() * (getScreenHeight() - 1) * getScreenBPP();
	memcpy(start,secondLine,size);
}


void drawDec(uint64_t value){
	drawBase(value, 10);
}

void drawHexa(uint64_t value){
	drawBase(value, 16);
}

void drawBin(uint64_t value){
	drawBase(value, 2);
}

void drawBase(uint64_t value, uint32_t base){
	static char buffer[64] = { '0' };
    intToBase(value, buffer, base);
    drawString(buffer);
}


void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 


char* intToBase(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 







