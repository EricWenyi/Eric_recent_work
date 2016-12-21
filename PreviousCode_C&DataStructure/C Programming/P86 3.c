/*******************put a fraction into the lowest term*****************/

#include<stdio.h>

int main(void)
{
	int m,n,p,a,b;
	
    printf("Enter a fraction:");
	scanf("%d/%d",&m,&n);
	
	a=m;
	b=n;
	
	while (b != 0){
		p=a%b;
		a=b;
		b=p;
	}
	
	printf("In lowest term:%d/%d",m/a,n/a);
	return 0;
}
