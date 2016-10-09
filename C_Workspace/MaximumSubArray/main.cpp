#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int current_sum = 0;
        int larget_sum = INT_MIN;

        for(size_t i = 0;  i < nums.size(); i++){
            current_sum += nums[i];
            if(current_sum > larget_sum)
                larget_sum = current_sum;
            if(current_sum < 0)
                current_sum = 0;

        }

        return larget_sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
