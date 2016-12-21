/****************ACME checkbook-balancing program***********/

#include<stdio.h>

int main(void)
{
	int cmd;
	float balance= 0.0f,credict,debit;
	
	printf("ACME checkbook-balancing program\n");
	printf("Command: 0=clear,1=credict,2=debit,3=balance,4=exit\n");
	for (;;){		
	printf("Enter commend:");
	scanf("%d",&cmd);
	
	switch (cmd){
		case 0:balance=0.0f;
		break;
		case 1:printf("Enter the amount of credict:");
		       scanf("%f",&credict);
		       balance += credict;
		       break;
		case 2:printf("Enter the amount of debit:");
		       scanf("%f",&debit);
		       balance -= debit;
		       break;
		case 3:printf("Currrent balance:$%.2f\n",balance);
			   break;
        case 4:return 0;       
	  }
	}
}