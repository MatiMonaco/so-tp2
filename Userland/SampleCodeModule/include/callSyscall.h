#ifndef CALLSYSCALL_H
#define CALLSYSCALL_H
#include <stdint.h>

#define READ 3
#define WRITE 4

void callSyscall(uint64_t id,void* param1,void* param2,void* param3,void* param4,void* param5,void* param6);
#endif