/*******************Change 24-hour systerm into 12-hour systerm************/

#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter a 24-hour time:");
	scanf("%d:%d",&a,&b);
	
	printf("Equvalent 12-hour time:");
	
	if (a>12)
	
	switch (a){
		case 13 : printf("1");break;
		case 14 : printf("2");break;
		case 15 : printf("3");break;
		case 16 : printf("4");break;
		case 17 : printf("5");break;
		case 18 : printf("6");break;
		case 19 : printf("7");break;
		case 20 : printf("8");break;
		case 21 : printf("9");break;
		case 22 : printf("10");break;
		case 23 : printf("11");break;
		case 24 : printf("0");break;
		default : printf("invalid number");break;
	}
	
	else printf("%d",a);
	
	printf(":%.2d",b);
	
	if (a<12)
	printf(" AM");
	else 
	printf(" PM");
	
	return 0;	
}

