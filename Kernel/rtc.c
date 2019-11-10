#include <stdint.h>
#include <rtc.h>
#include <screenDriver.h>
#include <libc.h>

void displayDateTime(){
	getCurrDate();
	drawString(" - ");
	getCurrTime();
}

void getCurrTime(){
	char hs[3];
	intToBase(getCurrHs(),hs,10);
	uint64_t mins = getCurrMins();
	uint64_t secs = getCurrSecs();
	drawString(hs);
	/*
	drawChar(':',0xFFFFFF,0x000000);	
	drawDec(mins);
	drawChar(':',0xFFFFFF,0x000000);	
	drawDec(secs);	
	*/
}

void getCurrDate(){
	/*
	uint64_t day = getCurrDay();
	uint64_t month = getCurrMonth();
	uint64_t year = getCurrYear();
	drawDec(day);
	drawChar('/',0xFFFFFF,0x000000);	
	drawDec(month);
	drawChar('/',0xFFFFFF,0x000000);	
	drawDec(year);	
	*/
}