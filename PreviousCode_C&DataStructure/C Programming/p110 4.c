/***************print a phone number *************/

#include<stdio.h>

int main()
{
	char ch;
	
	printf("Enter phone number:");
	
	
	ch=getchar();
	while (ch != '\n')
		{
		    switch (ch) {
			case 'A':case 'B':case 'C': putchar('2');break;
			case 'F':case 'D':case 'E': putchar('3');break;
			case 'G':case 'H':case 'I': putchar('4');break;
			case 'J':case 'K':case 'L': putchar('5');break;
			case 'M':case 'N':case 'O': putchar('6');break;
			case 'P':case 'Q':case 'R':case 'S': putchar('7');break;
			case 'T':case 'U':case 'V': putchar('8');break;
			case 'W':case 'X':case 'Y':case 'Z': putchar('9');break;
			default:putchar(ch);break;
		}
		ch=getchar();
	}
	
	return 0;
}

