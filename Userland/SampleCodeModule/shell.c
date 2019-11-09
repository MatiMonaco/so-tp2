#include <shell.h>
#include <stdio.h>
void initShell(){
printf("hola");
	while(1){
		char c;
		while((c = getchar()) != '\n'){
			if(c == 'a'){
				putchar('a');
			}
			putchar(c);
		}
		
	}
		
	
}