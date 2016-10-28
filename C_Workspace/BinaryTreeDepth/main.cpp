#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */

    int maxDepth(TreeNode *root) {
        // write your code here
        if(root == NULL)
            return 0;

        int n_left = maxDepth(root->left);
        int n_right = maxDepth(root->right);

        return (n_left>n_right) ? (n_left + 1) : (n_right + 1);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
