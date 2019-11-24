#include <stdint.h>

int beepasm();
int unbeepasm();
void beep(int ticks);
void activateBeep();
void deactivateBeep();

uint64_t init_sound();