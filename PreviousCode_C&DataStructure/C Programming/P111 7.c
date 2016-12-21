/********Enter to fractions and operation character*******************/

#include<stdio.h>

int main()
{
	printf("Enter two fractions separated by a +, -, * or / sign:");
	
	int  num1,num2,denom1,denom2;
	char ch;
	
	scanf("%d/%d",&num1,&denom1);
	ch=getchar();
	scanf("%d/%d",&num2,&denom2);
	
	if (ch=='+')
	printf("The sum is:%d/%d",num1*denom2+num2*denom1,denom1*denom2);
	else if(ch=='-')
	printf("The difference is:%d/%d",num1*denom2-num2*denom1,denom1*denom2);
	else if(ch=='*')
	printf("The product is:%d/%d",num1*num2,denom1*denom2);
	else if(ch=='/')
	printf("The quotient is:%d/%d",num1*denom2,denom1*num2);
	return 0;
}

