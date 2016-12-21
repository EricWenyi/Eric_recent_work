/*******************Broker and his opponent***********/

#include<stdio.h>

int main()
{
	int num;
	float price,total,com,opp;
	
	printf("Enter the price of stock:");
	scanf("%f",&price);
	printf("Enter the number of stock:");
	scanf("%d",&num);
	
	total=num*price;
	
	if (total<2500.00f)
	  com=30.00f + .017*total;
	else if(total<6250.00f)
	  com=56.00f + .0066f*total;
    else if(total<20000.00f)
	  com=76.00f + .0034f*total;
    else if(total<6250.00f)
	  com=155.00f + .0011f*total;
    else
      com=255.00f + .0009*total;
      
    if (com<39.00f)
      com=39.00f;
      
    printf("Commission:%.2f\n",com);
	
	if (num<2000)
	opp = .033f*num + 0.03f;
	else 
	opp = .033f*num + 0.02f;
	
	printf("opponent commission:%.2f",opp);
	
	return 0; 	  
}
