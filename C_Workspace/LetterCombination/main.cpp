#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;

        if(digits.size() == 0){
            return res;
        }

        string digitalmap[] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        res.push_back("");

        for(int i = 0; i < digits.size(); i++){
            vector<string> temp;
            for(int j = 0; j < res.size(); j++){
                for(int p = 0; p < digitalmap[digits[i] - '0'].size(); p++)
                    temp.push_back(res[j] + digitalmap[digits[i] - '0'][p]);
            }

            res = temp;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> letters = s.letterCombinations("23");

    for(size_t i = 0; i < letters.size(); i++){
        cout<<letters[i]<<" ";
    }

}
