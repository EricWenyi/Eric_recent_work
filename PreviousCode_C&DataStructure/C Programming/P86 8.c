/***********Calendar*************/

#include<stdio.h>

int main()
{
	int i,n,a,p,q;
	printf("Enter number of days in month:");
	scanf("%d",&n);
	printf("Enter starting day of week:");
	scanf("%d",&a);
	for (p=1;p<=3*(a-1);p++){
	printf(" ");}
	
	for (i=1;i<=n;i++){
		
	printf("%2d ",i);
	
	if (a==8-(i%7))
	printf("\n");	
	}
	return 0;
}