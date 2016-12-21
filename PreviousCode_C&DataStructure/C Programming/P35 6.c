/********Enter to fractions and plus them*******************/

#include<stdio.h>

int main()
{
	printf("Enter two fractions sparated by a plus sign:");
	
	int  num1,num2,denom1,denom2;
	
	scanf("%d/%d+%d/%d",&num1,&denom1,&num2,&denom2);
	
	printf("The sum is:%d/%d",num1*denom2+num2*denom1,denom1*denom2);
	
	return 0;
} 

