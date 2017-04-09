#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        vector< vector<int> > res;
        int n = candidates.size();

        BacktrackingSum(candidates, target, 0, sum, res);
        return res;
    }

    void BacktrackingSum(vector<int>& candidates, int subtarget, int index, vector<int>& sum, vector<vector<int> > &res){

        if(subtarget == 0){
            res.push_back(sum);
            return;
        }

        while(index < candidates.size() ){
            if(candidates[index] <= subtarget){
                sum.push_back(candidates[index]);
                BacktrackingSum(candidates, subtarget - candidates[index], index + 1, sum, res);
                sum.pop_back();
            }
            index++;
        }
        return;
    }

};

int main()
{
    vector< vector<int> > res;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(4);
    candidates.push_back(3);

    int target = 7;

    Solution s;
    res = s.combinationSum(candidates, target);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}
