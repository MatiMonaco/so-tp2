#ifndef CALLSYSCALL_H
#define CALLSYSCALL_H
#include <stdint.h>


#define WIDTH 1
#define HEIGHT 2
#define READ 3
#define WRITE 4
#define SPEAKER 5 
#define DRAW_RECT 6
#define SLEEP 7
#define DRAW_CIRCLE 8
#define TIME 9
#define CLEAR 10
#define SECONDS_ELAPSED 11
#define ERROR -1

uint64_t callSyscall(uint64_t id,void* param1,void* param2,void* param3,void* param4,void* param5,void* param6);

#endif