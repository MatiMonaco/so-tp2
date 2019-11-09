#include <stdint.h>
#include <syscalls.h>

#define READ 3
#define WRITE 4
#define INFOREG 5

uint64_t syscallDispatcher(uint64_t id, void* param1, void* param2, void* param3, void* param4, void* param5, void* param6){
    switch(id){
        case WRITE:
            return write((uint64_t)param1,(const char*) param2,(uint64_t) param3);//
            break;

		case READ:
			 return read((uint64_t)param1,(char*) param2,(uint64_t) param3);//
		break;
		    
	   /* case INFOREG:
            printRegisters();
            break;*/
    }
    /*
    void (*functions[])(void*,void*,void*,void*,void*,void*) = {};
    (*functions[rax])(rdi,rsi,rdx,r10,r9,r8);
    */
}




