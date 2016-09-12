#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int > > results;

        if(nums.size() < 3){
            return results;
        }

        int i = 0;

        std::sort(nums.begin(), nums.end());

        for(i = 0; i < nums.size(); i++){
            int target = -nums[i];

            int front = i+1;
            int back = nums.size() - 1;

            while(front < back){
                if(nums[front] + nums[back] < target)
                    front++;
                else if(nums[front] + nums[back] > target){
                    back--;
                }
                else{
                    vector<int> triple(3,0);
                    triple[0] = nums[i];
                    triple[1] = nums[front];
                    triple[2] = nums[back];

                    results.push_back(triple);

                    while(front < back && nums[front] == triple[1]) front++;

                    while(front < back && nums[back] == triple[2]) back--;

                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }

        return results;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
