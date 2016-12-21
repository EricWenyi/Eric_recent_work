/*************calculate point***************/

#include<stdio.h>
#include<ctype.h>

int main()
{
	char ch;
	int i,total=0;
	
	printf("Enter a word:");
	ch = getchar();
	ch=toupper(ch);
	while (ch != '\n'){
		switch(ch){
			case 'A':case 'E':case 'I':case 'L':case 'N':case 'O':case 'R':case 'S':case 'T':case 'U':
			i=1;break;
			
			case 'D':case 'G':i=2;break;
			case 'B':case 'C':case 'M':case 'P':i=3;break;
			case 'F':case 'H':case 'V':case 'W':case 'Y':i=4;break;
			case 'K':i=5;break;
			case 'J':case 'X':i=8;break;
			case 'Q':case 'Z':i=10;break;
		}
		total+=i;
		ch=getchar();
		ch=toupper(ch);	
	}
	printf("Scrabble value: %d",total);
	return 0;
}
