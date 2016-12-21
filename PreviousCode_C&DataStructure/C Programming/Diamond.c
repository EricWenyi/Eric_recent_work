#include<stdio.h>
#define n 5
int main(void){
	int row,col,i;
	for(row=1;row<=n;row++){                           /*  \n   */
		for(col=1;col<=n-row;col++){                    /*   space  */
			printf(" ");
		}
		for(i=1;i<=2*row-1;i++){                          /*  '*'    */
			printf("*");
		}
		printf("\n");
	}
	for(row=1;row<=n-1;row++){                          /*   \n   */
	  for(col=1;col<=row;col++){                                  /*   space  */
		printf(" ");
	}
	for(i=2*(n-row)-1;i>=1;i--){                          /* '*'   */
		printf("*");
	}                                      
		printf("\n");
	}
	return 0;
}
