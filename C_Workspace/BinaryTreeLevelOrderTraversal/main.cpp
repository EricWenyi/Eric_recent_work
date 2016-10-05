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



class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > results;
        deque<TreeNode*> Node_queue;
        Node_queue.push_back(root);

        while(!Node_queue.empty()){
            vector<int> LevelResules;
            size_t n = Node_queue.size();
            for(size_t i = 0; i < n; i++){
                LevelResules.push_back(Node_queue[i]->val); //first get the answers
            }



            for(size_t i = 0; i < n; i++){//pop root and push_back lft and right children
                TreeNode *temp = Node_queue.front();
                Node_queue.pop_front();
                if(temp->left != NULL)
                    Node_queue.push_back(temp->left);
                if(temp->right != NULL)
                    Node_queue.push_back(temp->right);
            }

            results.push_back(LevelResules);
        }

        return results;

    }
};


int main()
{
    TreeNode* root = new TreeNode(2);
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(3);
    TreeNode* three = new TreeNode(4);

    root->left = one;
    root->right = two;
    two->left = three;

    vector<vector<int> > results;
    Solution s;
    results = s.levelOrder(root);

    for(int i = 0; i < results.size(); i++){
        for(int j = 0; j < results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }


}
