#include <stdio.h>
#include <callSyscall.h>
#include <graphics.h>

static SCREEN_WIDTH = getScreenWidth();
static SCREEN_HEIGHT = getScreenHeight();

uint64_t drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color){

	return callSyscall(DRAW_RECT,(void*)x,(void*)y,(void*)width,(void*)height,(void*)color,(void*)0);
}
void clearScreen(){
	
	drawRect(0,0,WIDTH,HEIGHT,0x000000);

}

uint64_t getScreenWidth(){
	return callSyscall((void*)WIDTH,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}
uint64_t getScreenHeight(){
	return callSyscall((void*)HEIGHT,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}

