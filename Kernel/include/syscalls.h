#ifndef SYS_CALLS_H
#define SYS_CALLS_H
#include <stdint.h>
uint64_t write(uint64_t fd,const char* buffer,uint64_t count);
uint64_t read(uint64_t fd,char * buffer,uint64_t count);
#endif