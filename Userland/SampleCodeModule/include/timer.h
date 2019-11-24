#include <stdint.h>
uint64_t getSeconds();
uint64_t sleep(uint64_t ticks);


typedef struct{
  int seconds;
  int minutes;
  int hours;
  int day;
  int month;
  int year;
}tm;
