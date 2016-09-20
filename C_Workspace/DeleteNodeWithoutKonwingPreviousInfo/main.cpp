#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
 };

class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(node->next != NULL){
            int temp = node->next->val;
            node->val = temp;
            node->next = node->next->next;
        }
        else{
            node = NULL;
        }

    }
};

int main()
{
    cout<<NULL<<endl;
    ListNode *head = new ListNode(5);
    ListNode *one = new ListNode(6);
    ListNode *two = new ListNode(7);
    head->next = one;
    one->next = two;

    Solution s;
    s.deleteNode(two);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
}
