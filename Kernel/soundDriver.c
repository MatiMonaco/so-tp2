#include <soundDriver.h>
#include <time.h>

void beep(int ticks){
  activateBeep();
  int end = ticks_elapsed() + ticks;
  while(ticks_elapsed() < end);
  deactivateBeep();
  //newTimer(timer, deactivateBeep);
}

void activateBeep(){
  beepasm();
}

void deactivateBeep(){
  unbeepasm();
}
