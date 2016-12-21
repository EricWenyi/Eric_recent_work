/*******************Broker and his opponent***********/

#include<stdio.h>

int main()
{
	float value,total,com,opp;
		
		do{
	printf("Enter value of trade:");
	scanf("%f",&value);
	if (value == 0)
	break;
	else if(value<2500.00f)
	  com=30.00f + .017*value;
	else if(value<6250.00f)
	  com=56.00f + .0066f*value;
    else if(value<20000.00f)
	  com=76.00f + .0034f*value;
    else if(value<6250.00f)
	  com=155.00f + .0011f*value;
    else
      com=255.00f + .0009*value;
      
    if (com<39.00f)
      com=39.00f;
      
      
      
    printf("Commission:%.2f\n",com);
	}
	while (value!= 0);
    return 0;
	  
}
