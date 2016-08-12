#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        int p1,p2;

        p1 = 0;
        p2 = nums.size() - 1;

        while(p1 <= p2){

            while(nums[p2] == val){
                p2--;
            }

            if(nums[p1] == val){
                int temp;
                temp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = temp;
                p1++;
                p2--;
            }
            else{
                p1++;
            }
        }

        return p1+1 ;
    }
};

int main()
{
    vector<int> nums;

    for(int i = 0; i < 5; i++){
        nums.push_back(i);
    }

    Solution s;
    int n = s.removeElement(nums,3);
    for(size_t i = 0; i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }

    cout<<n;

}
