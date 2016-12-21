#include<stdio.h>

int power(int x,int n);

int main()
{
	int x,n;
	
	printf("Enter value for x: ");
	scanf("%d",&x);
	printf("Enter value for n: ");
	scanf("%d",&n);
	
	printf("x raised to the power n: %d\n",power(x,n));
	
	return 0;
} 

int power(int x,int n)
{
	if (n==0)
	return 1;
	
	if ((n%2)==1)
	return x*power(x,n-1);
	if ((n%2)==0)
	return (power(x,n/2)*power(x,n/2));
	
}
