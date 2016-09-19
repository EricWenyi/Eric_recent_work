#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if(nums.size() < 2){
            return;
        }
        int find_even, find_odd;

        find_even = 0;
        find_odd = nums.size() - 1;

        while(find_even < find_odd){
            while(nums[find_even] % 2 != 0 && find_even < find_odd) find_even++; //nums[find_even] is now a even
            while(nums[find_odd] % 2 == 0 && find_even < find_odd) find_odd--; //nums[find_odd] is now an odd

            cout<<nums[find_even]<<" "<<nums[find_odd]<<endl;

            //switch the value
            int temp;
            temp = nums[find_even];
            nums[find_even] = nums[find_odd];
            nums[find_odd] = temp;

        }
    }
};


int main()
{
    int arr[] = {2,4,1,3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution s;
    s.partitionArray(nums);

    for(size_t i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";

    return 0;
}
