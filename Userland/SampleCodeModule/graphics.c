
#include <callSyscall.h>
#include <graphics.h>



static uint64_t SCREEN_HEIGHT;
static uint64_t SCREEN_WIDTH;

uint64_t drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color){
	return callSyscall(DRAW_RECT,(void*)x,(void*)y,(void*)width,(void*)height,(void*)color,(void*)0);
}

const uint64_t getScreenWidth(){
	return callSyscall(WIDTH,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}
const uint64_t getScreenHeight(){
	return callSyscall(HEIGHT,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}

uint64_t drawCircle(uint64_t x,uint64_t y,uint64_t radius,uint64_t color){
	return callSyscall(DRAW_CIRCLE,(void*)x,(void*)y,(void*)radius,(void*)color,(void*)0,(void*)0);
}

uint64_t clearScreen(){
	return callSyscall(CLEAR,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}

void init(){
 SCREEN_WIDTH = getScreenWidth();
 SCREEN_HEIGHT = getScreenHeight();
}
