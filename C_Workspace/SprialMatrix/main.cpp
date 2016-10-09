#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int> > generateMatrix(int n) {
        // Write your code here
        int turn = ceil(double(n) / 2);
        vector<vector<int> > results;


        int counter = 1;


        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                temp.push_back(INT_MAX);
            }
            results.push_back(temp);
        }

        for(int i = 0; i < turn; i++){
            IteInitial(i, n, results, counter);
        }

        return results;

    }

    void IteInitial(int turn, int n, vector<vector<int> > &results, int &counter){
        if(n - 2*turn == 1){
            results[turn][turn] = n*n;
        }
        else{
            int i = 0;
            int j = 0;
            for( i = turn, j = turn; j < n - turn - 1; j++){//round 1
                results[i][j] = counter;
                counter++;
            }

            for(i = turn, j = n - turn - 1; i < n - turn - 1; i++){//round 2
                results[i][j] = counter;
                counter++;
            }

            for(i = n - turn - 1, j = n - turn - 1; j > turn; j-- ){//round 3
                results[i][j] = counter;
                counter++;
            }

            for(i = n - turn - 1, j = turn ; i > turn; i--){ // round 4
                results[i][j] = counter;
                counter++;
            }
        }

        return;
    }
};

int main()
{
    vector<vector<int> > results;

    Solution s;
    results = s.generateMatrix(3);

    for(size_t i = 0; i < results.size(); i++){
        for(size_t j = 0; j < results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
}
