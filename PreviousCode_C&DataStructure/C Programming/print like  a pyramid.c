/**************print * like a pyramid****************************/

#include<stdio.h>

int main()
{
	int row,col,i;
	
	for (row=1;row<=5;row++){
		for (col=1;col<=5-row;col++){
			printf(" ");
		};
		for (i=1;i<=2*row-1;i++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
