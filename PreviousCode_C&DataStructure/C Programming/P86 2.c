/******************calculate the GCD of 2 numbers******************/

#include<stdio.h>

 int main(void)
 {
 	int m,n,p;
 	printf("Enter two integers:");
 	scanf("%d %d",&m,&n);
 	
 	if (m<n){
	 	p=n;
	 	n=m;
	 	m=p;
	 }
 	
 	if (n==0)/******************** "== "   no "="***************/
 	printf("Greatest common divisor:%d",m);
 	else{
	 while(n!=0){
 		p=m%n;
 		m=n;
 		n=p;
 	}
 	}
 	
 	printf("Greatest common divisor:%d",m);
	return 0; 	 
	 
 }