#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int dp[n] = {0};
            int max = nums[0];

            dp[0] = nums[0];

            for(int i = 1; i < n; i++){
                dp[i] = nums[i] + (dp[i -1] > 0 ? dp[i - 1] : 0);

                if(dp[i] > max)
                    max = dp[i]
            }

            return max;
        }
};
