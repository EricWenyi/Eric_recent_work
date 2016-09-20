#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> results;
        if(n <= 0){
            return results;
        }

        subs(results,n);

        return results;
    }

    int subs(vector<int> &results, int n){
        int base;

        if(n == 0)
            return 1;

        base = subs(results, n - 1);
        int size = results.size();
        for(int i = 1; i < 10; i++){
            results.push_back(base * i);
            for(int j = 0; j < size; j++){
                results.push_back(results[j] + base * i);
            }
        }

        return base * 10;

    }
};

int main()
{
    vector<int> nums;

    Solution s;
    nums = s.numbersByRecursion(2);

    for(size_t i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
}
