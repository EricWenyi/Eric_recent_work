/*******Check numbers for repeated digits************/

#include<stdio.h>

#define true 1

#define false 0

typedef int Bool;  

int main()
{
	Bool ds[10] = {false};
	int digit;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	while (n>0){
	  while (n>0){
		digit = n%10;
		if (ds[digit])
		break;
		
		ds[digit]=true;
		n=n/10;
	  }
		printf("Enter a number: ");
	    scanf("%ld",&n);
	}
	
	if (n>0)
	  printf("Repeated digit\n");
	else 
	  printf("No repeated digit\n");
	  
	return 0;    	   
}