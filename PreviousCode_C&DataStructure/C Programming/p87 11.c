/*****calculate e****************/

#include<stdio.h>

int main(void)
{
	int i,n;
	float e,x;
	
	e = 1;
	x = 1;
	printf("Enter a number:");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++){
		x *= i;
		e += (1/x);
	}

	printf("%f",e);
	return 0;
}
