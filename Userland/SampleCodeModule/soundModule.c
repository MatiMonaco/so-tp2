#include <soundModule.h>
#include <callSyscall.h>
void beep(uint64_t time){
	callSyscall(SPEAKER,(void*)time,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}