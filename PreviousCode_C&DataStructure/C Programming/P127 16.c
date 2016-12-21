/********figure out whether the two numbers are anagrams**************/

#include<stdio.h>
#include<ctype.h>

int main()
{
	char ch[40];
	int i,j,k,alphabet[26]={0};
	
	k=0;
	
	printf("Enter first word: ");
	for (i=0;i<40;i++){
		ch[i] = getchar();
		if (ch[i]=='\n')
		break;
		else 
		ch[i]=tolower(ch[i]);
		
		if (isalpha(ch[i])){
			j=ch[i]-97;
			alphabet[j]++;
		}
			
	}
	
	printf("Enter second word: ");
	for (i=0;i<40;i++){
		ch[i] = getchar();
		if (ch[i]=='\n')
		break;
		else 
		ch[i]=tolower(ch[i]);
		
		if (isalpha(ch[i])){
			j=ch[i]-97;
			alphabet[j]--;
		}	
	}
	
	for (i=0;i<26;i++){
		if(alphabet[i] != 0)
		k++;
	}
	
	if (k==0)
	printf("The words are anagrams.");
	else 
	printf("The words are not anagrams.");
	
	return 0;
}
