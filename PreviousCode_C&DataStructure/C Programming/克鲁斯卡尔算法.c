/*****************this is a Kruskal Algorithms********************/

#include<stdio.h>

#define maxnode 265

typedef struct
{
	int v1;
	int v2;
	int cost;

}arc;

arc edges[maxnode];

int find(int vex[],int v)
{
	int t;
	t = v;
	while(vex[t]>0)
	  t = vex[t];
	  
	return t;  
}

void Kruskal(arc edge[],int n)
{
	int vex[maxnode];
	int i,vex1,vex2;
	
	for (i = 0;i<n+1;i++)
	  vex[i] = 0;
	  
    for (i =1;i<n+1;i++)
    {
    	vex1 = find(vex,edge[i].v1);
    	vex2 = find(vex,edge[i].v2);
    	
    	if (vex2 != vex1)
    	{
	    	vex[vex2] = vex1;
	    	printf("Vexs: %6d %6d\t",edge[i].v1,edge[i].v2);
	    	printf("Weight: %d\n",edge[i].cost);
	    }
    	
    }
}


int main(void)
{
	int i,j;
	int n = 0;
	
	printf("Enter the number of the edges: ");
	scanf("%d",&n);
	
	for (i = 1; i<n+1 ;i++)
	{
		printf("Enter the number of vex1: ");
		scanf("%d",&edges[i].v1);
		
		printf("Enter the number of vex2: ");
		scanf("%d",&edges[i].v2);
		
		printf("Enter the weight of the edge: ");
		scanf("%d",&edges[i].cost);
		
		printf("\n");
	}
	
	arc max;
	
	
	for (i = n ; i>0 ; i--)
	{
		for (j = 1 ; j<i ; j++)
		{
			if (edges[j].cost > edges[j+1].cost)
			{
				max = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = max;
			}
		}
	}
	
	Kruskal(edges,n);
	
	return 0;
	
}

