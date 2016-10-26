#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
     int findK(int k,int num){
        stringstream ss;
        string snum;
        int counter = 0;

        ss<<num;
        ss>>snum;

        for(size_t i = 0; i < snum.size(); i++){
            if(snum[i] - '0' == k)
                counter++;
        }

        return counter;
     }

    int digitCounts(int k, int n) {
        // write your code here
        int res = 0;
        for(int i = 0; i <= n; i++){
            res += findK(k,i);
        }

        return res;
    }


};

int main()
{
    Solution s;
    cout<<s.digitCounts(1,12);
}
