#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()){
            return digits;
        }
        bool flag = true;

        for(int i = digits.size() - 1; i >= 0; i--){
            OverFlow(digits[i],flag);
            if(!flag){
                break;
            }
        }
        if(flag){
            digits[0] = 1;
            digits.push_back(0);
        }


        return digits;
    }

    void OverFlow(int& digit, bool& flag){
        if(flag){
            if(digit != 9){
                digit++;
                flag = false;
            }
            else{
                digit = 0;
                flag = true;
            }
        }
    }
};

int main()
{
    vector<int> results;
    results.push_back(9);


    Solution s;
    results = s.plusOne(results);

    for(size_t i = 0; i < results.size(); i++){
       cout<<results[i]<<" ";
    }

    return 0;
}
