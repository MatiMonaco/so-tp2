#include <stdio.h>
#include <string.h>
#include <libc.h>
#include <callSyscall.h>



void putchar(char c){
	callSyscall(WRITE,(void*) 1,(void*)&c,(void*)1,(void*)0,(void*)0,(void*)0);
}
char getchar(){
	char c;

	while(callSyscall(READ,(void*)0,(void*)&c,(void*)1,(void*)0,(void*)0,(void*)0) == 0);
	return c;
}
/*
void printf(const char* buffer){
	callSyscall(WRITE,(void*)1,(void*)buffer,(void*)strlen(buffer),(void*)0,(void*)0,(void*)0);
}*/
void printf(const char* format, ...){
  va_list arg;
  va_start(arg, format);
  int i;
  char* s;
  for(; *format != 0; format++){
    if(*format == '%'){
      format++;
      switch(*format){
            case 'c' :
              i = va_arg(arg,int);
              putchar(i);
              break;

            case 'd' :
              i = va_arg(arg,int);
              printDec(i);
             break;

            case 's':
              s = va_arg(arg,char*);
              while(*s){
                putchar(*s);
                s++;
              }
              break;
      }
    }else{
      putchar(*format);
    }
  }
}/*

void scanf(char*buffer){
	char c;
	while((c = getchar()) != '\n'){
		*buffer = c;
		putchar(*buffer);
		buffer++;
		
	}
	*buffer = '\0';

}
*/
int scanf(char* format, ...){
  va_list arg;
  va_start(arg, format);
  int i = 0;
  char c;
  int reading = 1;
  void * loadValue;
  int valuesLoaded = 0;
  int number = 0;

  while((c = getchar()) != '\n' && c != 0){
    if(!reading && c == format[0])
      reading = 1;
    if(reading){
      if(format[i] == '%'){
        loadValue = va_arg(arg,void *);
        switch(format[i+1]){
            case 'c' :
              *(char *)loadValue = c;
              break;
            case 'd' :
              do{
                number *= 10;
                number += (c - '0');
              }while((c = getchar()) >= '0' && c <= '9');

              *(int *)loadValue = number;
              number = 0;
              break;
            case 's':
              do{
                *(char *)loadValue = c;
                loadValue++;
              }while((c = getchar()) != ' ' && c != '\n' && c != 0);
              break;
        }
        valuesLoaded++;
      }
      else if(c != format[i]){
        reading = 0;
        continue;
      }
      i++;
    }
  }
  return valuesLoaded;
}
void perror(const char * buffer){
	callSyscall(WRITE,(void*)2,(void*)buffer,(void*)strlen(buffer),(void*)0,(void*)0,(void*)0);
}


void printDec(uint64_t value){
	printBase(value, 10);
}

void printHexa(uint64_t value){
	printBase(value, 16);
}

void printBin(uint64_t value){
	printBase(value, 2);
}

void printBase(uint64_t value, uint32_t base){
	static char buffer[64] = { '0' };
    intToBase(value, buffer, base);
    printf(buffer);
}




