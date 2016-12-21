#include<stdio.h>
int main(void)
{
	char ch,fn;
	printf("Enter a first and last name: ");
	fn=getchar();
	while((ch=getchar())!=' '){
		;
	}
	while((ch=getchar())!= '\n'){
		putchar(ch);
		
	}
	putchar(',');
	putchar(' ');
	putchar(fn);
	putchar('.');
	return 0;
}