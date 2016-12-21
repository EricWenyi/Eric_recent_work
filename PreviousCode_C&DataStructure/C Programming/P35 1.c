/********print date**********************/ 

#include<stdio.h>
 int main(void)
 {
 	printf("Enter a date(mm/dd/yyyy/):");
 	
 	int m,d,y;
 	
 	scanf("%d /%d /%d",&m,&d,&y);
 	
 	printf("you enter the date %d%.2d%d",y,m,d);
 	
 	return 0;
 }
 
 