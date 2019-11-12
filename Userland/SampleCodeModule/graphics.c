#include <stdio.h>
#include <callSyscall.h>
#include <graphics.h>




void init(){
 SCREEN_WIDTH = getScreenWidth();
 SCREEN_HEIGHT = getScreenHeight();
}

uint64_t drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color){

	return callSyscall(DRAW_RECT,(void*)x,(void*)y,(void*)width,(void*)height,(void*)color,(void*)0);
}
void clearScreen(){
	
	drawRect(0,0,getScreenWidth(),getScreenHeight(),0x000000);

}

const uint64_t getScreenWidth(){
	return callSyscall(WIDTH,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}
const uint64_t getScreenHeight(){
	return callSyscall(HEIGHT,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}

