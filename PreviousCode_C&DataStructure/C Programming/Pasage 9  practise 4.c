#include<stdio.h>

int max_value (int a[3][4]);

int main()
{
	int i,j,a[3][4];
	
	printf("Enter element of matrix (3x4): ");
	for (i=0;i<3;i++){
		for (j=0;j<4;j++)
		scanf("%d",&a[i][j]);
	}
	
	printf("Largest element: %d",max_value(a));
	return 0;
}

int max_value(int a[3][4]){
	int i,j,max=0;
	for (i=0;i<3;i++){
		for (j=0;j<4;j++){
			if (a[i][j]>max)
			max = a[i][j];
		}
		
	}
	return max;
}

