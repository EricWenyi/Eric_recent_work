/***************feibonaqi shulie *********************/

#include<stdio.h>

int main()
{
	int fib_number[15],i;
	
	fib_number[0]=0;
	fib_number[1]=1;
	
	for (i=2;i<15;i++){
		fib_number[i]=fib_number[i-1]+fib_number[i-2];
	}
	for (i=0;i<15;i++){
		printf("%d ",fib_number[i]);
	}
	
	return 0;
}
