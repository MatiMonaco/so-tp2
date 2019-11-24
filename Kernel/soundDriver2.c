#include <sound2.h>


extern void io_write(uint16_t port, uint8_t data);
extern uint8_t io_read(uint16_t port);

void soundOn(int frec) {
 int freq;
 uint8_t aux;
 freq = 1193180 / frec;
 io_write(PIT_CONFIGURE_PORT, 0xb6);
 io_write(PIT_3_PORT, (uint8_t) (freq) );
 io_write(PIT_3_PORT, (uint8_t) (freq >> 8));

 aux = io_read(NOT_KEYBOARD_PORT);
   if (aux != (aux | 3)) {
   io_write(NOT_KEYBOARD_PORT, aux | 3);
 }
}


void soundOff() {
 uint8_t aux = io_read(NOT_KEYBOARD_PORT) & 0xFC;
 io_write(NOT_KEYBOARD_PORT, aux);
}

void beep() {
  soundOn(100);
  time_wait(10);
  soundOff();
}
