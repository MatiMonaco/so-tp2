#include <time.h>
#include <naiveConsole.h>
static unsigned long ticks = 0;
static int lastsec = 0;

void timer_handler() {
	ticks++;
	
	int currsec = seconds_elapsed();
	if(currsec != lastsec && currsec % 5 == 0){
		if(currsec % 10 == 0){
			ncPrintInPos("-5s-",(uint8_t*)0xB8100);
		}
		else{
			ncPrintInPos(".5s.",(uint8_t*)0xB8100);
		}
		lastsec = currsec;
	}
	
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}
