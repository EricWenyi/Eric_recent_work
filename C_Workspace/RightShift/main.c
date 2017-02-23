#include <stdio.h>
#include <stdlib.h>

int solution(int N){
    int largest = 0;   //here we change 0 to N
    int shift = 0;
    int temp = N;
    int i;
    for(i = 1; i < 30; ++i){
        int index = (temp & 1);
        temp = ( (temp >>  1) | (index << 29  ) );
        printf("%d\n", temp);

        if(temp > largest){
            largest = temp;
            shift = i;
        }
    }

    return shift;
}

int main()
{
    int N = 2048;
    solution(N);
}


