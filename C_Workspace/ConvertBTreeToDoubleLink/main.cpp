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
        DoublyListNode *head = new DoublyListNode();

        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL){
            head->val = root->val;
            head->next = NULL;
            head->prev = NULL;
        }
        else{
            head->val = root->val;
            head->prev = bstReLeft(root->left,head);
            head->next = bstReRight(root->right,head);
        }

        return head;
    }

    DoublyListNode* bstReLeft(TreeNode* root, DoublyListNode* head){
        DoublyListNode *node = new DoublyListNode();

        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL){
            node->val = root->val;
            node->next = head;
            node->prev = NULL;
        }
        else{
            head->val = root->val;

        }
    }

    DoublyListNode* bstReRight(TreeNode* root, DoublyListNode* head){
        if(root == )
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
