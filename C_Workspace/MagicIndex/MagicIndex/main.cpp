//
//  main.cpp
//  MagicIndex
//
//  Created by 邬文弈 on 06/10/2017.
//  Copyright © 2017 Eric. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int divide(vector<int> nums, int lo, int hi){
    if(lo > hi) return -1; // Attention
    int mid = (lo + hi) / 2;
    if(nums[mid] == mid) return mid;
    else if(nums[mid] > mid) return divide(nums, lo, mid - 1 /* Attention*/);
    else return divide(nums, mid + 1/* Attention*/, hi);
}

int magicIndex(vector<int> nums){
    int res = divide(nums, 0, nums.size() - 1);
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
