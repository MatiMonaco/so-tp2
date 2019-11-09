#include <video_vm.h>
#include <screenDriver.h>
#include <font.h>

unsigned int x = 0;
unsigned int y = 0;

static void scrollDown();

void drawChar(char character, int fontColor, int backgroundColor){
    if(x == getScreenWidth()){
        if(y == getScreenHeight()){
            scrollDown();
        }
        else{
            y++;
        }
		x = 0;
    }
	if(c == '\n'){
		newline();
	}
	else if(c == '\b'){
		deleteChar();
	}
	else{
    	drawCharAt(x++,y,character,fontColor,backgroundColor);

}

void scrollDown(){
	char * screen = getFrameBuffer();
	
}

void newline(){
	if(y == getScreenHeight()){
		scrollDown();
	}
	else{
		y++;
	}
	x = 0;
}

void deleteChar(){
	if(y != 0 || x != 0){
		if(x == 0){
			x = getScreenWidth();
			y--;
			drawCharAt(x,y,' ',0xFFFFFF,0x000000);
		}
		else{
			x--;
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