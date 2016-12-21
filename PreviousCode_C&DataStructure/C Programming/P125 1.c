/*******Check numbers for repeated digits************/

#include<stdio.h>

#define true 1
#define false 0

typedef int Bool;  

int main()
{
	int  ds[10];
	int digit,i;
	long n;
	
	do {
	for (i=0;i<10;i++)
	ds[i]=0;
		
	printf("Enter a number: ");
	scanf(" %ld",&n);
	
	if (n<=0)
	break;
	while (n>0){
		digit = n%10;
		ds[digit]++;
		n=n/10;
	}
	
	Bool j=false;
	for (i=0;i<10;i++){
		if (ds[i]>1)
		j++;
	}
	
	if (j){
		printf("Repeated digit(s): ");
		for (i=0;i<10;i++){
			if (ds[i]>1)
			printf("%d ",i);
		}
	}
	else 
	printf("No repeated digit");
	
	printf("\n");
	
	}   while (n>=0);

	  
	return 0;    	   
}
