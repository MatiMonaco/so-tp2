
#include <syscall_dispatcher.h>

void sys_write(char * string, int size){
  callSyscall((uint64_t) WRITE, 1, (uint64_t) string, (uint64_t)size, 0, 0);
}
char sys_read(char * string, int size){
  return callSyscall(READ, 1, (uint64_t) string, size, 0, 0);
}




void sys_new_line(){
	callSyscall((uint64_t) NEW_LINE, 0, 0, 0, 0, 0);
}



void sys_beep(){
  callSyscall(BEEP,0,0,0,0,0);
}
