#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        cout<<matrix[0][0]<<endl;
        if(matrix[1][0] == NULL){
            cout<<"SHENMEGUI"<<endl;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0;
        int j = col - 1;
        int NumberOfTarget = 0;

        while( i >= 0 && i < row && j >=0 && j < col){
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
            else{
                NumberOfTarget++;
                i++;
                j--;
            }

        }
        return NumberOfTarget;

    }
};


int main()
{
    vector<vector<int> > matrix;
    vector<int> colume;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 15; j++){
            colume.push_back(0);
        }

        matrix.push_back(colume);
        colume.clear();
    }

    Solution s;
    int number = s.searchMatrix(matrix,0);

    cout<<number<<endl;

    return 0;
//    cout<<matrix.size()<<endl;
//    cout<<matrix[0].size()<<endl;

 }
