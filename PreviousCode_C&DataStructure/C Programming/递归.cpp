#include<stdio.h>

int jiecheng(int n)
{
	if (n==1)
	return 1;
	else 
	return (n*jiecheng(n-1));
}

int main()
{
	int n,answer;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	
	answer = jiecheng(n);
	
	printf("Answer is %d",answer);
	
	return 0;
	
} 