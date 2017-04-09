#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int hi = n - 1;
        int lo = 0;
        int mid = (hi + lo) / 2;

        while(lo < hi){
            if(nums[mid] > target)
                hi = mid;
            else if(nums[mid] < target)
                lo = mid + 1;
            else
                return mid;

            mid = (hi + lo) / 2;
        }

        return lo;
    }
};

int main(){
    cout<< 1 / 2 <<endl;
    return 0;
}
