#include <stdint.h>
#include <syscalls.h>
#include <kbDriver.h>
#include <screenDriver.h>
#define STDIN 0
#define STDOUT 1
#define STDERR 2

uint64_t write(uint64_t fd, const char* buffer,uint64_t count){
    switch(fd){
        case STDOUT:
            
			while(count > 0){
				drawChar(*buffer,0xFFFFFF,0x000000);
				buffer++;
				count--;
			}
			
            break;
        case STDERR:
          while(count > 0){
				drawChar(*buffer,#FF0000,0xFFFFFF);
				buffer++;
				count--;
			}

            break;
			default:
			break;
    }
    return 0;
}

uint64_t read(uint64_t fd,char * buffer,uint64_t count){
	switch(fd){
        case STDOUT:
				while(count > 0){
				getKeyASCII(buffer);
				buffer++;
				count--;
			}
            break;
		default:
			break;
    }
    return 0;
	
}