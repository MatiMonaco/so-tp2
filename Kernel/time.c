#include <time.h>
#include <screenDriver.h>
static unsigned long ticks = 0;
static int lastsec = 0;

typedef struct{
	int ticks;
	void (*callback)();
}timer;


timer timers[30];
int index = 0;

void timer_handler() {
	ticks++;
	
}

int ticks_elapsed() {
	return ticks;
}

void newTimer(int ticks, void (*callback)()){
	timers[index].ticks = ticks;
	timers[index].callback = callback;
	index++;
}




int seconds_elapsed() {
	return ticks / 18;
}

void time_wait(int n_ticks){
	_sti();
	int goal_ticks = ticks + n_ticks;
	while(ticks < goal_ticks){
		_hlt();
	}
}
