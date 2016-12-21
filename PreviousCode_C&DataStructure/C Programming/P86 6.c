/***********print the square of all even number***************/

#include<stdio.h>

int main()
{
	int i,n;
	printf("Enter a number:");
	scanf("%d",&n);
	
	i=2;
	while (i<=n){
		printf("%d\n",i*i);
		i += 2;
	}
	return 0;
}
