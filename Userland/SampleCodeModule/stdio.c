#include <stdio.h>
#include <string.h>
#include <callSyscall.h>
void putchar(char c){
	callSyscall(WRITE,(uint64_t)1,(const char*)&c,(uint64_t)1,0,0,0);
}
char getchar(){
	char c;
	callSyscall(READ,(char *)&c,(uint64_t)1,0,0,0,0);
	return c;
}

void printf(const char* buffer){
	callSyscall(WRITE,(uint64_t)1,(const char*)buffer,(uint64_t)strlen(buffer),0,0,0);
}

void scanf(char*buffer){
	char c;
	while((c = getchar()) != '\n'){
		*buffer = c;
		buffer++;
	}

}

