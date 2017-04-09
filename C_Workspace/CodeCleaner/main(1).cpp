#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int hi = n - 1;
        int lo = 0;


        while(lo <= hi){
            int mid = (hi + lo) / 2;

            if(nums[mid] >= target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};

int main(){
    cout<< 1 / 2 <<endl;
    return 0;
}
