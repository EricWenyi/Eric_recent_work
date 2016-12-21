/***************Print a number in a backward way****************/

#include<stdio.h>

int main()
{
	int a,b,c;
	
	printf("Enter a two-digit number:");
	scanf("%d",&c);
	
	a=c % 10 ; 
	b=c / 10 ;
	
	printf("The reversal is:%d%d",a,b);
	
	return 0;
} 

