/***************count the number of the vowel letters**************/

#include<stdio.h>

int main()
{
	printf("Enter a sentence: ");
	char ch;
	int i=0;
	
	ch = getchar();
	while (ch != '\n'){
		switch(ch){
			case 'a':case 'o':case 'u':case 'i':case 'e':i++;break;
		}
		ch=getchar();
	}
	printf("your santence contains %d vowels",i);
	
	return 0;
}
