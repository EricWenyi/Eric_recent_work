/***************Ensure the capacity*******************/

#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter a number:");
	scanf("%d",&a);
	
	if (a<=9)
	printf("The number %d has 1 digit",a);
	else if (a<=99)
	printf("The number %d has 2 digits",a);
	else if (a<=999)
	printf("The number %d has 3 digits",a);
	else if (a<=9999)
	printf("The number %d has 4 digits",a);
	else printf("Out of range!");
	
	return 0;
}

