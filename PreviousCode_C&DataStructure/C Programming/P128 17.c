/***********magic square***************/

#include<stdio.h>


void magic_cube (int n);


int main()
{
	int n;
	
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	
	magic_cube(n);
	
	return 0;
}

void magic_cube(int n)
{
	int i,j,k;
	int a[99][99];
	
	for (i=0;i<99;i++){
		for (j=0;j<99;j++)
		a[i][j]=0;
	}
	
	i=0;
	j=((n+1)/2)-1;
	k=1;
	
	while (k <= (n*n)){
		a[i][j]=k;
		k++;
		i--;
		j++;
		
		if (i == -1)
		i=n-1;
		
		if (j == n)
		j=0;
		
		if (a[i][j] != 0){
			if (j==0)
			j = n;
			if (i==n-1)
			i=-1;
			
			i++;
			j--;
			i++;
			
			}
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
		printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}