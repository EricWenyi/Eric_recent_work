/***********************Homework P24 8********************/

#include<stdio.h>

int main()
{
	float total,rate,payment;
	int i,n;
	printf("Enter amount of loan:");
    scanf("%f",&total);
	printf("Enter interest rate:");
    scanf("%f",&rate);
	printf("Enter monthly payment:");
	scanf("%f",&payment);
	printf("Enter the frequency of payment:");
	scanf("%d",&n);
	
	for (i=1;i<=n;i++){
		total -= (payment+total*0.01*rate/12);
		printf("Money remaining:%f\n",total);
		
		if (total<0)
		printf("Money remaining:0");
	}
	return 0;
}

