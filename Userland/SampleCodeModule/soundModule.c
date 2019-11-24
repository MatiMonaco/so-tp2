#include <soundModule.h>
#include <callSyscall.h>
void beep(int time){
	callSyscall(SPEAKER,(void*)time,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);
}