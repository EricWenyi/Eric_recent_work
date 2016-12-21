/*****Print a table of aquares using a for statement*******/

#include<stdio.h>

int main()
{
	int i,n,odd,square;
	
	printf("Enter number of entries in table:");
	scanf("%d",&n);
	
	for (i=1,odd=3;i<=n;odd+=2){
		i++;
		square+=odd;
		
	printf("%10d%10d\n",i,square);
	}
	return 0;
}
