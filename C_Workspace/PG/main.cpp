#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };

class DoublyListNode {
 public:
     int val;
     DoublyListNode *next, *prev;
     DoublyListNode(int val) {
         this->val = val;
           this->prev = this->next = NULL;
     }
 };

class Solution{
public:
    void test(DoublyListNode* head){
        test2(&head);
        cout<<head->val<<endl;
       // cout<<head->next->val<<endl;

        return;
    }

    void test2(DoublyListNode** head_pointer){
        DoublyListNode *p = new DoublyListNode(2);

        (*head_pointer)->next = p;
        p->prev = (*head_pointer);

        *head_pointer = p;

        return;
    }
};

int main()
{
    DoublyListNode *head = new DoublyListNode(1);
    Solution s;
    s.test(head);

    return 0;
}
