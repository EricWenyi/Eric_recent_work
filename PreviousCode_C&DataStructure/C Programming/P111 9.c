/**************change a 12-hour time into 24-hour time*************/

#include<stdio.h>

int main()
{
	int hour,min;
	char ch;
	printf("Enter a 12-hour time: ");
	scanf("%d:%d",&hour,&min);
	
	ch=getchar();
	ch=getchar();
	
	if (ch=='P'){
		hour += 12;	
	}
	
	printf("Equialent 24-hour time: %.2d:%.2d",hour,min);
	
	return 0;
	
}
