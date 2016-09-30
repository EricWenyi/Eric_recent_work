#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        int hash_tableA[128] = { };
        int hash_tableB[128] = { };

        for(size_t i = 0; i < A.size(); i++){
            hash_tableA[A[i] - '0']++;
        }

        for(size_t i = 0; i < B.size(); i++){
            hash_tableB[B[i] - '0']++;
        }

        for(int i = 0; i < 128; i++){
            if(hash_tableA[i] != hash_tableB[i]){
                return false;
            }

        }

        return true;
    }
};



int main()
{
    string A = "ABC";
    string B = "BAC";

    Solution s;
    cout<<s.stringPermutation(A,B);
}
