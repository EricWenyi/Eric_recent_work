/**************Calculate the income tax in American**********/

#include<stdio.h>
int main()
{
	int in;
	float tax;
	printf("Enter the income:");
	scanf("%d",&in);
	
	if (in<=750)
	tax = in*0.01f;
	else if(in<=2250)
	tax = 7.50f + (in-750)*.02f;
	else if(in<=3750)
	tax = 37.50f + (in-2250)*.03f;
	else if(in<=5250)
	tax = 82.50f + (in-3750)*.04f;
	else if(in<=7000)
	tax = 142.50f + (in-750)*.05f;
	else 
	tax = 230.00f + (in-7000)*.06f;
	
	printf("The tax need to be paid:%.2f",tax);
	
	return 0;
}
