/************tell the user the largest number*******************/

#include<stdio.h>

int main(void)
{
	float a,max;
	max=0;
	
	do {
		printf("Enter a number:");
	    scanf("%f",&a);
	    if (a>=max){
    	 max=a;
    	}
	   
	}
	while (a>0);
	
	printf("The largest number entered was %.2f",max);
	return 0;
}
