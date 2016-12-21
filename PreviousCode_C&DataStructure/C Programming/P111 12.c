/********************simple calculater******************/

#include<stdio.h>

int main()
{
	double lo,ro,result;
	char ch;
	
	printf("Enter an expression:");
	scanf("%lf",&lo);
	ch=getchar();
	
	while (ch != '\n'){
		
		scanf("%lf",&ro);
		
		if (ch=='+')
		lo += ro;
		else if(ch=='-')
		lo -= ro;
		else if(ch=='*')
		lo *= ro;
		else if(ch=='/')
		lo /= ro;
		
		ch=getchar();
	}
	printf("Value of expression:%f",lo);
	return 0;
}
