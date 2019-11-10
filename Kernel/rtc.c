#include <stdint.h>
#include <rtc.h>
#include <screenDriver.h>

void GetCurrTime(){
	uint64_t hs = getCurrHs();
	uint64_t mins = getCurrMins();
	uint64_t secs = getCurrSecs();
	drawDec(hs);
	drawChar(':',0xFFFFFF,0x000000);	
	drawDec(mins);
	drawChar(':',0xFFFFFF,0x000000);	
	drawDec(secs);	
}