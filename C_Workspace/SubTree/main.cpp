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

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here

        //first to check whether there is a root value the same with T2

        bool result = false;

        if(T1 != NULL && T2 != NULL){
            if(T1->val == T2->val){
                result = isTheSame(T1,T2);
            }
            if(!result){
                result = isSubtree(T1->left,T2);
            }
            if(!result){
                result = isSubtree(T1->right,T2);
            }
        }

        return result;
    }

    bool isTheSame(TreeNode* T1, TreeNode* T2){
        if(T1 == NULL && T2 == NULL)
            return true;
        else if(T1 == NULL && T2 != NULL)
            return false;
        else if(T1 != NULL && T2 == NULL)
            return false;

        if(T1->val != T2->val)
            return false;
        else
            return (isTheSame(T1->left,T2->left) && isTheSame(T1->right,T2->right));
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
