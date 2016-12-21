/************extrat the square root of a number************/

#include<stdio.h>
#include<math.h>

double square_root (double a,double b);
int main()
{
	double x,y;
	
	printf("Enter a positive number: ");
	scanf("%lf",&x);
	printf("Square root: %.5lf",square_root(x,y));
	
	return 0;
}

double square_root(double a,double b){
	b=1.0;
	double c,d,f;
	do {
		c = a/b;
		d = (b+c)/2;
		f = fabs(b-d);
		b = d;
	}while (f>0.0001);
	return b;
	}