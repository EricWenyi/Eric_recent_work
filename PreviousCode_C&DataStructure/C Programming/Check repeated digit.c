/*******Check numbers for repeated digits************/

#include<stdio.h>

#define true 1
#define false 0

typedef int Bool;  

int main()
{
	int  ds[10] = {0};
	int digit;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	while (n>0){
		digit = n%10;
		if (ds[digit])
		ds[digit]++;
		n=n/10;
	}
	
	Bool j=false;
	for (int i=0;i<10;i++){
		if (ds[i]>1)
		j=true;
	}
	
	if (j){
		printf("Repeated digit(s): ");
		for (int i=0;i<10;i++){
			if (ds[i]>2)
			printf("%d",ds[i]);
		}
	}
	else 
	printf("No repeated digit");

	  
	return 0;    	   
}
