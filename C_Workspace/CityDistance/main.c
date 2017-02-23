#include <stdio.h>
#include <stdlib.h>

struct Results{
    int *A;
    int N;
};

typedef struct Node{
    int ID;
    struct Node* next;
    int visited;
} List_node;



struct Results solution(int T[], int N){
    int i;
    //initialize return value
    struct Results *res = (struct Results *)malloc(sizeof(struct Results));
    res->A = (int *)malloc((N - 1) * sizeof(int));
    for(i = 0; i < N; i++){
        res->A[i] = 0;
    }
    res->N = N;

    //initialize array of pointers points to head of linked lists storing connection information
    List_node* Connection[N];

    for(i = 0; i < N; i++){
        Connection[i] = NULL;
    }

    //initialize array of pointers points to the end of each linked list
    List_node* EndConnection[N];
    for(i = 0; i < N; i++){
        EndConnection[i] = NULL;
    }


    int capital_index = -1;
    for(i = 0; i < N; i++){
        int index = i;
        int value = T[i];

        if(index == value){
            capital_index = index;
            continue;
        }

        //initialize a new list node containing value
        List_node* temp_value = (List_node*)malloc(sizeof(List_node));
        temp_value->ID = value;
        temp_value->next = NULL;
        temp_value->visited = 0;
        if(EndConnection[i] == NULL){
            Connection[i] = temp_value;
            EndConnection[i] =  temp_value;
        }
        else{
            EndConnection[i]->next = temp_value;
            EndConnection[i] = temp_value;
        }

        //initialize a new list node containing index
        List_node* temp_index = (List_node*)malloc(sizeof(List_node));
        temp_index->ID = index;
        temp_index->next = NULL;
        temp_index->visited = 0;
        if(EndConnection[value] == NULL){
            Connection[value] = temp_index;
            EndConnection[value] =  temp_index;
        }
        else{
            EndConnection[value]->next = temp_index;
            EndConnection[value] = temp_index;
        }
    }


//    int test = all_valid(Connection, 4, T);
//    printf("%d", test);

    int distance = 1;
    calculate_distance(Connection, capital_index, T, res->A, distance);
    return *res;
};

void calculate_distance(List_node* Connection[], int start_index, int T[], int* A, int distance){
    if(all_valid(Connection, start_index, T) == 0)
        return ;

    List_node* temp = Connection[start_index];
    while(temp != NULL){
        if(temp->visited == 0){
            A[distance - 1]++;
            temp->visited = 1;
        }
        else{
            temp = temp->next;
            continue;
        }

        calculate_distance(Connection, temp->ID, T, A, distance + 1);
        temp = temp->next;
    }

    return;
}

int all_valid(List_node *Connection[], int start_index, int T[]){
    int res = 0;
    List_node* temp = Connection[start_index];


    while(temp != NULL){
        if(T[start_index] == temp->ID){
            temp->visited = 1;
        }
        temp = temp->next;
    }


    temp = Connection[start_index];
    while(temp != NULL){
        if(temp->visited == 0){
            res = 1;
            break;
        }
        temp = temp->next;
    }

    return res;
}

int main()
{
    int N = 10;
    int T[10] = {9,0,1,2,3,4,5,6,7,9};

    struct Results res;
    res = solution(T, N);
    int i = 0;
    for(i = 0; i < res.N - 1; i++){
        printf("%d\n",res.A[i]);
    }
    return 0;
}
