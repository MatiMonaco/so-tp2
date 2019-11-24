#include <soundDriver.h>
#include <time.h>

void beep(int time){
  activateBeep();
  int end = ticks_elapsed() + 2;
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
