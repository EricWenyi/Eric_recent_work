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

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
            return NULL;

        int length = preorder.size();
        return ConstructCore(preorder,0,inorder,0,length);
    }

    TreeNode *ConstructCore(vector<int> &preorder,int start_pre, vector<int> &inorder, int start_in, int length){
        //set the root value first
        if(length == 0)
            return NULL;

        TreeNode *root = new TreeNode(preorder[start_pre]);
        root->left = NULL;
        root->right = NULL;


//        if(preorder[start_pre] == inorder[start_in])
//            return root;

        //find the root position in the inorder

        int i = start_in;
        while(inorder[i] != preorder[start_pre] && i < start_in + length){
            i++;
        }



        int left_length = i - start_in;
        int right_length = length - left_length - 1;

        root->left = ConstructCore(preorder, start_pre + 1, inorder, i - left_length, left_length);
        root->right = ConstructCore(preorder,start_pre + 1 + left_length, inorder, i + 1, right_length);

        return root;
    }

    void BFS(TreeNode *root){
        if(root != NULL){
            cout<<" "<<root->val<<",";
            BFS(root->left);
            BFS(root->right);
        }
        else
            cout<<" #,";
    }
};

int main()
{
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};

    vector<int> preorder(pre, pre + sizeof(pre) / sizeof(int));
    vector<int> inorder(in, in + sizeof(in) / sizeof(int));

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);

    TreeNode *temp = root->right;

    cout<<temp->val<<endl;

    temp  = temp->right;

    if(temp == NULL){
        cout<<"#"<<endl;
    }
    else{
        cout<<temp->val<<endl;
    }

    temp = temp->left;

    if(temp == NULL){
        cout<<"#"<<endl;
    }
    else{
        cout<<temp->val<<endl;
    }

    TreeNode *traverse = root;

    //s.BFS(root);


    return 0;
}
