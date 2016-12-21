/*************Make a 4*4 matrix*********************/


#include<stdio.h>

int main(void)
{
	printf("Enter the number from 1 to 16 in any order:");
	
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p);
	
	printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n",a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);
	printf("Row sums:%d %d %d %d\n",a+b+c+d,e+f+g+h,i+j+k+l,m+n+o+p);
	printf("Column sums:%d %d %d %d\n",a+e+i+m,b+f+j+n,c+g+k+o,d+h+l+p);
	printf("Dagonal sums:%d %d\n",a+f+k+p,m+n+o+p);
	
	return 0;
}
