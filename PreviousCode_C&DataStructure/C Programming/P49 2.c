/***************Print a number in a backward way****************/

#include<stdio.h>

int main()
{
	int a,b,c,d,e;
	
	printf("Enter a two-digit number:");
	scanf("%d",&c);
	
	d=c/100;
	e=c%100;
	a=e%10;
	b=e/10;
	
	printf("The reversal is:%d%d%d",a,b,d);
	
	return 0;
} 

