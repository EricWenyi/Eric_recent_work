/***************** tell the uder which date is ealier**************/

#include<stdio.h>

int main()
{
	int d1,d2,m1,m2,y1,y2;
	printf("Enter first date (mm/dd/yy):");
	scanf("%d/%d/%d",&m1,&d1,&y1);
	
	printf("Enter second date (mm/dd/yy):");
	scanf("%d/%d/%d",&m2,&d2,&y2);
	
	if (y1<=y2){
		if (y1=y2){
			if (m1<=m2){
				if (m1=m2){
					if (d1<d2)
					printf("%d/%d/%d is earlier than %d/%d/%.2d",m1,d1,y1,m2,d2,y2);
					else
                    printf("%d/%d/%d is earlier than %d/%d/%.2d",m2,d2,y2,m1,d1,y1);
				}else 
				 printf("%d/%d/%d is earlier than %d/%d/%.2d",m1,d1,y1,m2,d2,y2);
			}else 
			 printf("%d/%d/%d is earlier than %d/%d/%.2d",m1,d1,y1,m2,d2,y2);
		}else 
		  printf("%d/%d/%d is earlier than %d/%d/%.2d",m1,d1,y1,m2,d2,y2);
		
	}
	
	else 
	printf("%d/%d/%.2d is earlier than %d/%d/%.2d",m2,d2,y2,m1,d1,y1);
	
	return 0;
	
}

