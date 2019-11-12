#include <stdint.h>
#include <syscalls.h>


#define WIDTH 1
#define HEIGHT 2
#define READ 3
#define WRITE 4
#define SPEAKER 5 
#define DRAW_RECT 6
#define ERROR -1

typedef uint64_t(*SystemCall)();

static SystemCall syscall_array[] = {0,(SystemCall)sys_getWidth,(SystemCall)sys_getHeight,(SystemCall)sys_read,(SystemCall)sys_write,0,(SystemCall)sys_drawRect};

uint64_t syscallDispatcher(uint64_t id, void* param1, void* param2, void* param3, void* param4, void* param5, void* param6){
   return syscall_array[id](param1,param2,param3,param4,param5,param6);
}




