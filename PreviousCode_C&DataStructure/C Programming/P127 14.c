/*****************make message printed in a encrypted way**********/

#include<stdio.h>

int main()
{
	int i,j,k;
	char ch[100];
	
	printf("Enter a sentence: ");
	for (i=0;i<100;i++){
		ch[i]=getchar();
		if ((ch[i]=='!') || (ch[i]=='?') || (ch[i]=='.')){
		k=i;
		break;
		}
	}
	
	printf("Reversal of sentence: ");
	
	for (i=k;i>=0;i--){
		if (ch[i]==' '){
			for (j=i+1;j<k;j++){
			  if (ch[j]==' ')
		      break;
			  else 
			  putchar(ch[j]);
			}
			putchar(' ');
		}
		
		if (i==0){
			for (j=0;j<k;j++){
				if (ch[j]==' ')
				break;
				else 
				putchar(ch[j]);
			}
		}
		
	}
	putchar(ch[k]);
	
	return 0;
}

