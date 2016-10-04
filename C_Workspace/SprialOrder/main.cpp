#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        // Write your code here
        vector<int> results;
        if(matrix.empty())
            return results;

        size_t m = matrix.size();
        size_t n =  matrix[0].size();


        int round = ceil(double(min(m,n)) / 2);

        for(int mark = 0; mark < round; mark++){
            RecOrder(matrix,results,mark);
        }

        return results;
    }

    void RecOrder(vector<vector<int> >& matrix, vector<int>& results, int mark){
        size_t m = matrix.size();
        size_t n =  matrix[0].size();

        int i = 0;
        int j = 0;

        if(n - 2*mark == 1 && m - 2*mark != 1){
            for(i = mark, j = mark; i < m - mark ; i++){//round 2 only
                results.push_back(matrix[i][j]);
            }
            return;
        }
        else if(n - 2*mark != 1 && m - 2*mark == 1){
            for(i = mark, j = mark; j < n - mark; j++){
                results.push_back(matrix[i][j]);
            }
            return;
        }
        else if(n - 2*mark == 1 && m - 2*mark == 1){
            results.push_back(matrix[mark][mark]);
            return;
        }

        for( i = mark, j = mark; j < n - mark - 1; j++){//round 1
             results.push_back(matrix[i][j]);
        }
        for(i = mark, j = n - 1 - mark; i < m - mark - 1; i++){//round 2
            results.push_back(matrix[i][j]);
        }
        for(i = m - 1 - mark, j = n - 1 - mark; j > mark; j-- ){//round 3
            results.push_back(matrix[i][j]);
        }
        for(i = m - 1 - mark, j = mark; i > mark; i--){//round 4
            results.push_back(matrix[i][j]);
        }

        return;
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    vector<vector<int> > matrix;
    matrix.push_back(test);
    matrix.push_back(test);
    matrix.push_back(test);

    Solution s;
    vector<int> results;
    results = s.spiralOrder(matrix);
    for(int i = 0; i < results.size(); i++){
        cout<<results[i]<<" ";
    }
}
