#include<stdio.h>

int main(void) 
{
	struct {
		int a[10];
	}a,b;
	
	int i = 0;
	
	for (i = 0;i<10;i++){
		scanf("%d",&a.a[i]);
	}
	
	b = a;
	
	for (i = 0;i<10;i++)
	printf("%d\n",b.a[i]);
	
	return 0;
}