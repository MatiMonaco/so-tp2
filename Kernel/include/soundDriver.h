#include <stdint.h>

int beepasm();
int unbeepasm();
void beep(int ticks);
void activateBeep();
void deactivateBeep();
void set_frequency(int frequency);

void set_frequencyASM(int frenquency);
uint64_t init_sound();