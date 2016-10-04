#include <iostream>
#include<bits/stdc++.h>
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

class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if(root == NULL)
            return NULL;

        DoublyListNode *head = new DoublyListNode(0);

        if(root->left != NULL && root->right != NULL){
            //in-order recursively the tree
            RecTest(root, &head);
        }
        else{
            head->val = root->val;
        }

       while(head->prev != NULL){
            head = head->prev;
        }

        return head;

    }

    void RecTest(TreeNode* root, DoublyListNode** head){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            RecTest(root->left, head);
        }
        else if(root->left == NULL && root->right == NULL){//leaf node

            (*head)->val = root->val;
            //new a new obj
            DoublyListNode* new_head = new DoublyListNode(0);
            (*head)->next = new_head;
            new_head->prev = (*head);
            head = &new_head;
            delete new_head;

            return;
        }

        (*head)->val = root->val;
            //new a new obj
        DoublyListNode* new_head = new DoublyListNode(0);
        (*head)->next = new_head;
        new_head->prev = (*head);
        head = &new_head;
        delete new_head;

        if(root->right != NULL){
            RecTest(root->right, head);
        }

        return;
    }

};

int main()
{
    TreeNode *root = new TreeNode(2);
    TreeNode *left_c = new TreeNode(1);
    TreeNode *right_c = new TreeNode(3);

    root->left = left_c;
    root->right = right_c;

    Solution s;
    DoublyListNode *node = s.bstToDoublyList(root);

    while(node != NULL){
        cout<<node->val<<" ";
        node = node->next;
    }

    return 0;
}
