/*************B1FF translater*************/

#include<stdio.h>
#include<ctype.h>

int main()
{
	char F1BB_message[40];
	int i;
	
	printf("Enter message: ");
	for (i=0;i<40;i++){
	F1BB_message[i]=getchar();
	if (F1BB_message[i]=='\n')
	break;
	}
	
	printf("In B1FF-speak: ");
	for (i=0;(i<40)&&(F1BB_message[i] != '\n');i++){
		
		F1BB_message[i]=toupper(F1BB_message[i]);
		
		switch (F1BB_message[i]){
			case 'A':putchar('4');break;
			case 'B':putchar('8');break;
			case 'E':putchar('3');break;
			case 'I':putchar('1');break;
			case 'O':putchar('0');break;
			case 'S':putchar('5');break;
			default :putchar(F1BB_message[i]);break;
		}
	}
	printf("!!!!!!!!!!");
}