/**************calcuate the average length of a word in a setence***********/

#include<stdio.h>

int main()
{
	int i=0,n=0,b=0;
	char ch;
	double ave;
	
	printf("Enter a sentence:");
	ch = getchar();
	
	while (ch != '\n'){
		while (ch != ' '&& ch !='.'){
			i++;
			ch= getchar();
		}
		n+=i;
		i=0;
		ch=getchar();
		b++;
	}
	ave=((double)n)/b;
	printf("Average word length:%.2lf",ave);
	
	return 0;
}
