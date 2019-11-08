#include <stdint.h>
#include <syscalls.h>

void syscallDispatcher(uint64_t rax, void* rdi, void* rsi, void* rdx, void* r10, void* r9, void* r8){
    switch(rax){
        case 1:
            write((uint64_t)rdi,(const char*) rsi,(uint64_t) rdx);
            break;
    }
    /*
    void (*functions[])(void*,void*,void*,void*,void*,void*) = {};
    (*functions[rax])(rdi,rsi,rdx,r10,r9,r8);
    */
}




