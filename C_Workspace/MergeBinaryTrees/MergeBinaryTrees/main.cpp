//
//  main.cpp
//  MergeBinaryTrees
//
//  Created by 邬文弈 on 2017/8/13.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>


using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        
        int value = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
        TreeNode* NewNode = new TreeNode(value);
        NewNode->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        NewNode->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        
        return NewNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
