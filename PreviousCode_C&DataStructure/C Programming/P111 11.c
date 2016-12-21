/*****************print a formal name*****************/

#include<stdio.h>

int main()
{
	printf("Ener a first and last name: ");
	
	char ch,FN;
	
	FN=getchar();
	ch=getchar();
	
	while (ch != ' '){
    ch = getchar();            /*last character in ch is ' '*/
	}
	
    ch=getchar();
	             /*now is the fist letter of family name*/
    while (ch != '\n'){
    	putchar(ch);
    	ch=getchar();
    }
    putchar(',');
    putchar(' ');
    putchar(FN);
    putchar('.');
    
	return 0; 
}
