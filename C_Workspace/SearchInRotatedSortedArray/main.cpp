#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;


        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] >= nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int rot = hi;
        lo = 0 ;
        hi = nums.size() - 1;

        int reallo = 0 + rot;
        int realhi = (nums.size() - 1 + rot) % nums.size();


        while(lo < hi){
            int mid = (lo + hi) / 2;
            int realmid = (mid + rot) % nums.size();
            if(nums[realmid] == target)
                return realmid;
            else if(nums[realmid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
    }
};

int main()
{
    vector<int> nums;
    for(int i = 0; i < 6; i++){
        nums.push_back((3 + i) % 6);
    }
    int target = 3;

    Solution s;
    int res = s.search(nums, target);
    cout<<res<<endl;
}
