/**************Julius Caesar*************/

#include<stdio.h>

int main()
{
	printf("*** Julius Caesar coder-decorder program ***\n");
	
	printf("Commands: 0 = coder, 1 = decoder, 2 = exit\n\n");
	
	int c,amount,i,shift;
	char ch[80]={0};
	
	
	for (;;){
	printf("Enter command: ");
	scanf("%d",&c);
	
	switch (c){
		case 0:printf("Enter shift amount (1-25): ");
		       scanf("%d",&shift);
		       
		       while (shift<=0||shift>=26){
       			printf("Enter shift amount (1-25): ");
       			scanf("%d",&shift);
       		}
		       ch[0]=getchar();
		       
		       printf("Enter message to be encrypted: ");
		       for(i=0;(ch[i]=getchar())!='\n';i++)
		        ;
		       
		       for(i=0;i<=79;i++){
       			 if (ch[i]==0){
       			 amount=i;
       			 break;}
       		}
       		
       		printf("Encrypted message: ");
		       for (i=0;i<=amount;i++){
                 if (ch[i]>='a'&&ch[i]<='z'){
                 	ch[i]=((ch[i] - 'a')+shift)%26+'a';
                 }
                 
                
                 else if (ch[i]>='A'&&ch[i]<='Z'){
                 	ch[i]=((ch[i] - 'A')+shift)%26+'A';
                 }
                 
                putchar(ch[i]);
                 }
                 printf("\n");
                break;  /******************End of case 1****************/
                
         case 1: printf("Enter shift amount (1-25): ");
		       scanf("%d",&shift);
		       
		       while (shift<=0||shift>=26){
       			printf("Enter shift amount (1-25): ");
       			scanf("%d",&shift);
       		}
		       ch[0]=getchar();
		       
		       printf("Enter message to be decrypted: ");
		       for(i=0;(ch[i]=getchar())!='\n';i++)
		        ;
		       
		       for(i=0;i<=79;i++){
       			 if (ch[i]==0){
       			 amount=i;
       			 break;}
       		}
       		
       		printf("Decrypted message: ");
		       for (i=0;i<=amount;i++){
                 if (ch[i]>='a'&&ch[i]<='z'){
                 	ch[i]=((ch[i] - 'a')+shift)%26+'a';
                 }
                 
                
                 else if (ch[i]>='A'&&ch[i]<='Z'){
                 	ch[i]=((ch[i] - 'A')+shift)%26+'A';
                 }
                 
                putchar(ch[i]);
                 }
                 printf("\n");
                break;
		case 2:return 0;
		default: printf("Commands: 0 = coder, 1 = decoder, 2 = exit\n\n");	     
       		}
	}
}