#include <stdint.h>
#include <syscalls.h>
#include <naiveConsole.h>
#define STDIN 0
#define STDOUT 1
#define STDERR 2

uint64_t write(uint64_t fd, const char* buffer,uint64_t count){
    switch(fd){
        case STDOUT:
            
            ncPrint(buffer);
            break;
        case STDERR:
            ncPrintWithColor(buffer,0x04);
            break;
    }
    return 0;
}