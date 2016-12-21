/*****************************Change the format of the information****/

#include<stdio.h>

int main(void)
{
	int i,m,day,y;
	float p;
	
	printf("Enter item number:");
	scanf("%d",&i);
	
	printf("Enter unit price:");
	scanf("%f",&p);
	
	printf("Enter purchase date(mm/dd/yyyy):");
	scanf("%d/%d/%d",&m,&day,&y);
	
	printf("Item\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%6.2f\t%d/%d/%d",i,p,m,day,y);
	
	return 0;
}

