#include <video_vm.h>
#include <screenDriver.h>
#include <font.h>

unsigned int x = 0;
unsigned int y = 0;

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
	int g = getScreenHeight();
	for(int i = 0; i < getScreenWidth(); i++){
		drawCharAt(i,100,' ',0xFFFFFF,0x000000);
	}
	/*
	char * secondLine = (char*)(screenData->framebuffer + 100);
	int size = screenData->width * (screenData->height - 1);
	memcpy(start,secondLine,size);
	*/
}