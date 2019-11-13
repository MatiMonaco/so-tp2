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


static void fixScreen();
static void scrollUp();

void drawChar(char character, int fontColor, int backgroundColor){

	if(character == '\n'){
		newline();
	}
	else if(character == '\b' && (x != 0 && x != 0)){
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
	if(y >= 0){
		if(x == 0){
			x = getScreenWidth() - CHAR_WIDTH;
			y -= CHAR_HEIGHT;
			
		}
		else{

			x -= CHAR_WIDTH;
		}
		drawCharAt(x,y,' ',0xFFFFFF,0x000000);
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
	if(x < 0 || y < 0 || width < 0  || height <0 || width > getScreenWidth() || height > getScreenHeight() || x > getScreenWidth() || y > getScreenHeight()){
		return -1;
	}
	
	for(int i = x; i<  x + width;i++ ){
		for(int j = y; j < y + height; j++){
			drawPixel(i,j,color);
		}
	}
	return 1;
}

uint64_t drawCircle(unsigned int xc, unsigned int yc, int r, int color){
	for(int i = -r ; i <= r ; i++){
		for(int j = -r ; j <= r; j++){
			if(i*i + j*j <= r*r){
				drawPixel(xc+i,yc+j,color);
			}
		}
	}
}
