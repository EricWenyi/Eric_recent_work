/***************change number into level******************/

#include<stdio.h>

int main()
{
	int a,b,c;
	
	printf("Enter numerical grade:");
	scanf("%d",&c);
	
	if (c>100||c<0)
	printf("Invalid grade!");
	else if (c==100)  /*******pay attenction to "=="! ******/
	     printf("A");
	     else  
	     a=c/10;
	     b=c%10;
	
	switch(a){
		case 9:printf("A");break;
		case 8:printf("B");break;
		case 7:printf("C");break;
		case 6:printf("D");break;
		case 5:case 4:case 3:case 2:case 1:case 0:printf("F");break;
	}
	return 0;
	
}
