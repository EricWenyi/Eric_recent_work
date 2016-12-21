/*****************Show the occurrence of the number******************/

#include<stdio.h>

int main()
{
	int ds[10]={0},digit,i;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	while (n>0){
		digit = n%10;
		ds[digit]++;
		n=n/10;
	}
    
    printf("Digit:        ");
    for (i=0;i<=9;i++)
    printf("%d ",i);
    
    printf("\nOccurrences:  ");
    for(i=0;i<=9;i++)
    printf("%d ",ds[i]);
    
    return 0;
}
