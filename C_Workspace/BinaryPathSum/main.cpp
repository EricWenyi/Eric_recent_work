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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int> > binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here

        vector<vector<int> > results;
        vector<TreeNode*> paths;

        if(root == NULL)
            return results;

        RecPath(root,target,results,paths);
        return results;

    }

    void RecPath(TreeNode* root, int const target, vector<vector<int> > &results, vector<TreeNode*> paths){
        if(root == NULL)
            return;
        if(root->left != NULL || root->right != NULL){
            paths.push_back(root);
            RecPath(root->left, target, results, paths);
            RecPath(root->right, target, results, paths);
        }
        else{//is leaf
            paths.push_back(root);
            int temp = 0;
            for(size_t i = 0; i < paths.size(); i++){
                temp += paths[i]->val;
            }
            if(temp == target){
                vector<int> path_val;
                for(size_t i = 0; i < paths.size(); i++){
                    path_val.push_back(paths[i]->val);
                }
                results.push_back(path_val);
                paths.pop_back();
            }
            else{
                paths.pop_back();
            }
        }
        return;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);

    root->left = left;
    root->right = right;

    Solution s;
    vector<vector<int> > results;
    results = s.binaryTreePathSum(root,5);
    for(size_t i =0; i < results.size(); i++){
        for(size_t j = 0; j < results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }

}
