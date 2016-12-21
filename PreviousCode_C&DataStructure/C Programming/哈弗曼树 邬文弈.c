/*******************This is a Huffman Tree*************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MaxBit 10
#define MaxValue 1000

typedef struct Huffmannode{
	int weight;
	int parent,lchild,rchild;
}HFnode;

typedef struct Huffmancode{
	int bit[MaxBit];
	int start;
}HFcode;

void Huffmancoding(HFnode *HT,HFcode *HC,int *w,int n,int *b,int number)
{
	int i,j,m1,m2,m,x1,x2,start,c,f,k=0;
	HFnode *p;
	
	if (n<= 1)
	return;
	
	m = 2*n-1;
	
	HT = (HFnode *)malloc(m * sizeof(HFnode));
	
	for (p = HT,i = 0;i <n;i++,p++,w++){
		p->weight = *w;
		p->lchild = -1;
		p->rchild = -1;
		p->parent = -1;
	}
	
	for (i = n;i<m;++i,++p){
		p->weight = 0;
		p->lchild = -1;
		p->rchild = -1;
		p->parent = -1;
	}
	
	for (i = n;i<m;i++){
		m1 = MaxValue;
		m2 = MaxValue;
		x1 = 0;
		x2 = 0;
		
		for (j = 0;j<i;j++){
			if ((m1 >HT[j].weight)&& (HT[j].parent == -1)){
			m1 = HT[j].weight;
			x1 = j;	
			}
			
		}
		
		for (j = 0;j<i;j++)
		{
			if ((m2>HT[j].weight)&&(j!=x1)&&(HT[j].parent == -1)){
				m2 = HT[j].weight;
				x2 = j;
			}
		}

		HT[x1].parent = i;
		HT[x2].parent = i;
		HT[i].lchild = x1;
		HT[i].rchild = x2;
		HT[i].weight = m1 + m2;
	}
	
	
	HC = (HFcode *)malloc(n * sizeof(HFcode));
	for(i = 0;i < n;++i){
		
		start = MaxBit-1;
		
		for (c = i,f = HT[i].parent;f != -1;c=f,f = HT[f].parent){
			if (HT[f].lchild == c)
			HC[i].bit[start--] = 0;
			
			else
			HC[i].bit[start--] = 1;
		}
		HC[i].start = start+1;/******shu zu xing shi****/
	}
	
	
	
	for (i = 0;i<number;i++){
		     for (j = HC[b[i]].start;j<MaxBit;j++){
		          printf("%d",HC[b[i]].bit[j]);
		     }
		     
	}
}

int main(void)
{
	HFnode *HT;
	HFcode *HC;
	int w[99],n = 0,m,quantity[20],b[99],number = 0,i;
	char sequence[99];
	
	for (i = 0;i<20;i++){
		quantity[i] = 0;
	}

	printf("Enter a list of srting(Upper class): ");
	
	scanf("%s",sequence);
	
	number = strlen(sequence);
	
	
	for (i = 0;i<number;i++){
		b[i] = sequence[i]-65;
	}
	
	for(i = 0;i<number;i++){
		quantity[b[i]]++;
	}
	
	for (i = 0;i<number;i++){
		w[i] = quantity[b[i]];
	}
	
	for (i = 0;i<number;i++){
		if (b[i]>n)
		n = b[i];
	}
	
	n++;

	Huffmancoding(HT,HC,quantity,n,b,number);
	
	return 0;
	
}

