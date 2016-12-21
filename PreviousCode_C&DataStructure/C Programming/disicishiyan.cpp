/*******quick sort*************/

#include<stdio.h>

int quick_partition(int r[],int i,int j)
{
	r[0] = r[i];
	
	while (i<j){
		
		while (i<j && r[j]>=r[0])
		j--;
		
		r[i] = r[j];
		
		while (i<j && r[i]<=r[0])
		i++;
		
		r[j] = r[i];
		
	}
	
	r[i] = r[0];
	
	return i;
}

void quick_sort(int r[],int s, int t)
{
      int p;
	    
       if (s<t){
		p = quick_partition(r,s,t);
		quick_sort(r,s,p-1);
		quick_sort(r,p+1,t);
	}
}

int erfen_sort(int r[],int number, int n)
{
	int low = 1;
	int high = n;
	int mid = 0;
	
	while (low<= high)
	{
		mid = (low + high)/2;
		
		if (number == r[mid])
		return mid;
		
		else if(number >r[mid])
		low = mid+1;
		
		else
		high = mid -1;
	}
	
	return 0;
}

int main(void)
{
	int n,m,i,number;
	int r[256];
	
	printf("Enter the number of the sequence: ");
	scanf("%d",&n);
	
	printf("Enter the sequence: ");
	for (i = 1; i<n+1 ;i++)
	{
		scanf("%d",&r[i]);
	}
	
	m = 1;
	
	quick_sort(r,m,n);
	
	for (i = 1; i<n+1; i++)
	printf("%d ",r[i]);
	
	for(;;){
	printf("\nEnter the number you want to find: ");
	scanf("%d",&number);
	
	if (number == 0)
	return 0;
	
	i = erfen_sort(r,number,n);
	
	if (i == 0)
	printf("Do not find the number you want!");
	
	else 
	printf("The number is in %d position",i);
	}
	
	
}