#ifndef SYS_CALLS_H
#define SYS_CALLS_H
#include <stdint.h>
uint64_t sys_write(uint64_t fd,const char* buffer,uint64_t count);
uint64_t sys_read(uint64_t fd,char * buffer,uint64_t count);
uint64_t sys_drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint32_t color);
uint64_t sys_getHeight();
uint64_t sys_getWidth();
#endif