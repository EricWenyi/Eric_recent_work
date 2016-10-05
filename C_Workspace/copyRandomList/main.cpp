#include <iostream>
#include<bits/stdc++.h>
using namespace std;


 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here

        //first of all, copy the list
        if(head == NULL)
            return NULL;

        RandomListNode* node = head;

        while(node != NULL){
            RandomListNode* new_node = new RandomListNode(node->label);
            new_node->next = node->next;
            node->next = new_node;
            node = new_node->next;
        }

        //second copy the random pointer
        node = head; //reset node
        while(node != NULL){
            if(node->random != NULL){
                (node->next)->random = (node->random)->next;
                node = node->next->next;
            }
            else{
                (node->next)->random = NULL;
                node = node->next->next;
            }
        }

        node = SplitLinkedList(head);

        return node;
    }

    RandomListNode* SplitLinkedList(RandomListNode* origin){
        RandomListNode* results = origin->next;
        //RandomListNode* origin = head;
        RandomListNode* node;


        while(origin != NULL){
            node = origin->next;
            if(node->next == NULL){
                origin->next = NULL;
                break;
            }
            origin->next = node->next;
            node->next = origin->next->next;
            origin = origin->next;
        }

        return results;
    }
};

int main()
{
    RandomListNode *head = new RandomListNode(1);
    RandomListNode *two = new RandomListNode(2);

    head->next = two;

    Solution s;
    RandomListNode* node = s.copyRandomList(head);

    while(node != NULL){
        cout<<node->label<<endl;
        node = node->next;
    }

    return 0;
}
