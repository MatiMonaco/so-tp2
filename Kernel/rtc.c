#include <naiveConsole.h>
#include <rtc.h>

void GetCurrTime(){
	int hs = getCurrHs();
	int mins = getCurrMins();
	int secs = getCurrSecs();
	ncPrintDec(hs);
	ncPrint(" : ");
	ncPrintDec(mins);
	ncPrint(" : ");
	ncPrintDec(secs);
}
