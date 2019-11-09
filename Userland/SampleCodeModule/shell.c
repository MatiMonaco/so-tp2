#include <shell.h>
#include <stdio.h>
void initShell(){
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
	while(1){
		char c;
		while((c = getchar()) != '\n'){
			putchar(c);
		}
	}
		
	
}