#include <speaker.h>
#include <stdint.h>

void speaker()
{
  beep();
}

void beep()
{
 beepon();
  for (int i = 0; i < 1000000; i++) {
    ;
  }
  beepoff();
}
