/**************print a number in a backward squence***********/

#include<stdio.h>
int main()
{
	int m,n;
	printf("Enter a number:");
	scanf("%d",&n);
	
	do {
		m=n%10;
		n/=10;
		printf("%d",m);
	}while (n!=0);
	
	return 0;
}
