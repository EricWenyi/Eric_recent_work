#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> res;

        if(A.empty()){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        int start = 0;
        int backside = A.size() - 1;
        int middle = (start + backside)/2;

        while(start < backside){
            if(A[middle] < target){
                start = middle + 1;
                middle = (start + backside)/2;
            }
            else if(A[middle] >= target){
                backside = middle;
                middle = (start + backside)/2;
            }
        }

        if(A[middle] != target){
            res.push_back(-1);
            res.push_back(-1);
        }
        else{
            int i = middle;
            int j = middle;
            while(A[i] == target) i--;
            while(A[j] == target) j++;
            res.push_back(++i);
            res.push_back(--j);
        }

        return res;
    }
};

int main()
{
    int a[] = {1,2,3,3,3,34};
    vector<int> num(a,a + sizeof(a) / sizeof(int));

    Solution s;
    vector<int> res;
    res = s.searchRange(num,3);
    cout<<res[0]<<" "<<res[1]<<endl;
}
