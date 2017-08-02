//
//  main.cpp
//  ArrayPartition
//
//  Created by 邬文弈 on 2017/8/2.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i += 2){
            res += nums[i];
        }
        
        return res;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
