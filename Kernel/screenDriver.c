#include <video_vm.h>
#include <screenDriver.h>
#include <font.h>
#include <lib.h>
#include <stdint.h>

 unsigned int x = 0;
 unsigned int y = 0;


char* intToBase(int num, char* str, int base);
void reverse(char str[], int length);
void drawDec(uint64_t value);
void drawHexa(uint64_t value);
void drawBin(uint64_t value);
void drawBase(uint64_t value, uint32_t base);
void swap ( char *str1, char *str2 );
uint64_t drawRect(unsigned int x, unsigned int y,unsigned int width, unsigned int height, int color);


static void fixScreen();
static void scrollUp();

void drawChar(char character, int fontColor, int backgroundColor){

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
	fixScreen();

}
static void fixScreen(){
	if(x >= getScreenWidth()){

		newline();
	}
	
}

void newline(){
	y += CHAR_HEIGHT;
	if(y >= getScreenHeight()){
        scrollUp();
	
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

void scrollUp(){
	char *  start = (char * )getFrameBuffer();
	char *  secondLine = (char * )(getFrameBuffer() + getScreenWidth()*CHAR_HEIGHT*getScreenBPP());
	uint64_t size = getScreenWidth()*(getScreenHeight()-CHAR_HEIGHT)* getScreenBPP();
	
	memcpy(start,secondLine,size);
	y-=CHAR_HEIGHT;
	for(int i = 0; i< getScreenWidth(); i+=CHAR_WIDTH){
		drawCharAt(i,y,' ',0xFFFFFF,0x000000);
	}
	
}

uint64_t drawRect(unsigned int x, unsigned int y,unsigned int width, unsigned int height, int color){
	if(x < 0 || y < 0 || width < 0  || height <0 || width > getScreenWidth() || height > getScreenHeight()){
		return -1;
	}
	
	for(int i = 0; i< width;i++ ){
		for(int j = 0; j < height; i++){
			drawPixel(x,y,color);
		}
	}
}










