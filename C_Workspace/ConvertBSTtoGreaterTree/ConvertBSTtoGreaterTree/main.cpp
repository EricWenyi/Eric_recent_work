//
//  main.cpp
//  ConvertBSTtoGreaterTree
//
//  Created by 邬文弈 on 2017/8/13.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int value = 0;
        AddValue(root,value);
        return root;
    }
    
    void AddValue(TreeNode* origin, int& value){
        if(origin == NULL)
            return;
        
        if(origin->right != NULL)
            AddValue(origin->right, value);
        
        origin->val += value;
        value = origin->val;
        
        if(origin->left != NULL)
            AddValue(origin->left, value);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
