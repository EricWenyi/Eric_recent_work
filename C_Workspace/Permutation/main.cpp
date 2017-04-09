#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> chosen;
        vector<int> temp;
        const int n = nums.size();

        if(n == 0){
            return res;
        }

        generate_permutation(res, nums, chosen, n);
        return res;
    }

    void generate_permutation(vector<vector<int> >& res, vector<int>& nums, vector<int>& chosen, const int n){

        if(chosen.size() == n){
            res.push_back(chosen);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            chosen.push_back(nums[i]);
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            generate_permutation(res, nums, chosen, n);
            nums.insert(nums.begin() + i, temp);
            chosen.pop_back();
        }

        return;

    }
};

int main()
{
    Solution s;
    vector<vector<int> > res;
    vector<int> nums;
    for(int i = 0; i < 3; i++){
        nums.push_back(i);
    }

    res = s.permute(nums);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
