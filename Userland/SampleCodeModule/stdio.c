#include <stdio.h>
#include <string.h>
#include <callSyscall.h>
void putchar(char c){
	callSyscall(WRITE,1,&c,1,0,0,0);
}
char getchar(){
	char c;
	callSyscall(READ,&c,1,0,0,0,0);
	return c;
}

void printf(const char* buffer){
	callSyscall(WRITE,1,buffer,strlen(buffer),0,0,0);
}

void scanf(char*buffer){
	char c;
	while((c = getchar()) != '\n'){
		*buffer = c;
		buffer++;
	}

}

