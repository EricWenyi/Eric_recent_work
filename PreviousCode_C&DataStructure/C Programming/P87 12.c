/*****calculate e****************/

#include<stdio.h>

int main(void)
{
	int i;
	float e,x,p;
	
	e = 1;
	x = 1;
	printf("Enter value: ");
	scanf("%f",&p);
	
	for (i=1;e<=p;i++){
		x *= i;
		e += (1/x);
	}

	printf("The number that has been plused: %d",i);
	return 0;
}
