/***********Find the biggest and smallest number within 4 numbers***********/

#include<stdio.h>

int main()
{
	int a,b,c,d,max1,max2,min1,min2;
	
	printf("Enter four integers:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	if (a>b){
		max1=a;
		min1=b;}
    else {
	    max1=b;
		min1=a;}
		
	if(c>d){
	max2=c;
	min2=d;}
	  else
	{max2=d;
	min2=c;}
	
	if (max1>max2)
	printf("Largest number is:%d\n",max1);
	else 
	printf("Largest number is:%d",max2);
	
	if (min1<min2)
	printf("Smallest number is:%d\n",min1);
	else 	
	printf("Smallest number is:%d",min2);
	
	return 0;
	
}

