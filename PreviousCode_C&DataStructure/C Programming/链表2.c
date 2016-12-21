/*********This is a list***********************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct List
{
	char name[10];
	int age;
	struct List *next;
}Listnode, *listnodePtr;


void print_list(listnodePtr L)
{
	listnodePtr p = L->next;
	
	while (p != NULL){
		printf("%s\n",p->name);
		printf("%d\n",p->age);
		p = p->next;
	}
}

int Input_List(listnodePtr head)
{
	listnodePtr input;
	int shifou = 1;
	
	input = (listnodePtr)malloc(sizeof(Listnode));
	
	printf("Enter student information:");
	scanf("%s %d",&input->name,&input->age);
	
	if(input->age == 0){
		shifou = 0;
		free(input);
		return shifou;
	}
	
	input->next = head->next;
	head->next = input;
	
	return shifou;
}

int delet_list(listnodePtr L,listnodePtr delet_name)
{
	int shifou = 0;
	listnodePtr p;
	p = L;
	L = L->next;
	while (L != NULL){
		if(strcmp(L->name,delet_name->name) == 0){
			p->next = L->next;
			shifou = 1;
			return shifou;
		}
	p = L;
	L = L->next;
	}
    return shifou;
}
void reverse_list(listnodePtr L,listnodePtr L1_last)/***********L = head; *****/
{
	printf("Enter annother list: \n");
	
	listnodePtr head2,p,s;
	head2 = (listnodePtr)malloc(sizeof(Listnode));
	head2->next = NULL;
	
	int shifou = 1;
	for(;;){
			shifou = Input_List(head2);
			if (shifou != 1)
			break;
	}
	
	L1_last->next = head2->next;
	
	p = L->next;
	L->next = NULL;
	
	while(p != NULL){
		s = p;
		p = p->next;
		s->next = L->next;
		L->next = s;
	}
	
	printf("Reverse successfully!\n");
}

int main(void)
{
	listnodePtr head,delet,L1_last;
	int command,shifou;
	
	delet = (listnodePtr)malloc(sizeof(Listnode));
	head = (listnodePtr)malloc(sizeof(Listnode));
	head->next = NULL;
	
	printf("******************1.Input  2.Delet  3.Sort  4.Print the list 0.Break ********* \n");
	printf("Enter command: ");
	scanf("%d",&command);
		
	
	for(;;){
		switch(command){
			case 1:
			for(;;){
			shifou = Input_List(head);
			if (shifou != 1)
			break;
			}
			
			break;
			
			case 2:
			printf("Enter the name need to be deleted: ");
			scanf("%s",&delet->name);
			shifou = delet_list(head,delet);
			if (shifou)
			printf("Delet successfully!\n");
			else 
			printf("Invalid name!\n");
			break;
			
			case 3:
			L1_last = head;
			while(L1_last->next != NULL){
			L1_last= L1_last->next;
			}
			
			reverse_list(head,L1_last);
			break;
			
			case 4:print_list(head);
			break;
			
			case 0:
			return 0;
			
			default:
			printf("******************1.Input  2.Delet  3.Sort  4.Print the list 0.Break ********* \n\n");
		}
		
		printf("\nEnter command: ");
		scanf("%d",&command);
		
	}
	
}
