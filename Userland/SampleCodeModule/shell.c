#include <shell.h>
#include <stdio.h>
void initShell(){

	char c;
	printf("Buenas");
	while(1){
		while((c = getchar()) != '\n'){
			putchar(c);
		}
		
	}
		
	
}