#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void swap_value(int &a, int &b){
    a += b;
    b = a - b;
    a = a - b;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }


        size_t p,q;

        p = 0;
        q = 0;

        while(q < nums.size()){
            if(nums[p] != nums[q]){
                ++p;
                int temp;
                temp = nums[p];
                nums[p] = nums[q];
                nums[q] = temp;
                ++q;
            }
            else{
                ++q;
            }
        }
        return p+1;
    }
};

int main()
{
    vector<int> nums;

    for(int i = 1; i < 10; i++){
        nums.push_back(i);
    }

    Solution s;
    int n = s.removeDuplicates(nums);

    for(size_t i = 0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }

    cout<<n;
}
