#include <shell.h>
#include <stdio.h>
void initShell(){
printf("hola");
	while(1){
		char c;
		while((c = getchar()) != '\n'){
			putchar(c);
		}
	}
		
	
}