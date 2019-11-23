#include <soundDriver.h>
#include <time.h>

void beep(int time){
  activateBeep();
  int end = seconds_elapsed() + 1;
  while(seconds_elapsed() < end);
  deactivateBeep();
  //newTimer(timer, deactivateBeep);
}

void activateBeep(){
  beepasm();
}

void deactivateBeep(){
  unbeepasm();
}
