//
//  main.cpp
//  PlayGround2
//
//  Created by 邬文弈 on 2017/8/10.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
            for(int i = 0; i < len; i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        }
        
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res;
    Solution s;
    res = s.findDisappearedNumbers(nums);
    cout<<endl;
    for(int i: res){
        cout<<i<<endl;
    }
    
}
