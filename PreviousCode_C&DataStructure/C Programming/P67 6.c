/****************Check whethwe UPC is valid*****************/

#include<stdio.h>

int main(void)
{
	int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,y,fs,ss,total;
	
	printf("Enter the first (single) digit:");
	scanf("%1d",&d);
	printf("Emter first group of five digits:");
	scanf("%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5);
	printf("Enter second group of five digits:");
	scanf("%1d%1d%1d%1d%1d",&j1,&j2,&j3,&j4,&j5);
	
	fs=d+i2+i4+j1+j3+j5;
	ss=i1+i3+i5+j2+j4;
	total = 3+fs+ss;
	
	printf("Enter the check digit:");
	scanf("%d",&y);
	
	if (y=total)
	printf("Valid UPC");
	else 
	printf("Invalid UPC");
	
	return 0;
	
}
