#include <timer.h>
#include <stdint.h>
#include <callSyscall.h>

uint64_t getSeconds(){
	return callSyscall(SECONDS_ELAPSED,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}

uint64_t sleep(uint64_t ticks){
	return callSyscall(SLEEP,(void*)ticks,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}
/*
tm get_time(){
  tm time;
  time.seconds=sys_time(SECONDS_SELECTOR);
  time.minutes=sys_time(MINUTES_SELECTOR);
  time.hours=sys_time(HOURS_SELECTOR);
  time.day=sys_time(DAY_SELECTOR);
  time.month=sys_time(MONTH_SELECTOR);
  time.year=sys_time(YEAR_SELECTOR);
  print_time(time);
  return time;
}
*/