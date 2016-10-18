#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool compare(string A, string B){
        return ((A+B) < (B + A));
}

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */



    string minNumber(vector<int>& nums) {
        // Write your code here
        vector<string> s(nums.size());
        stringstream   stream;
        for(int i = 0; i < nums.size(); i++){
            stream << nums[i];
            stream >> s[i];
            stream.clear();
        }

        sort(s.begin(), s.end(), compare);

        string result = "";
        for(size_t i = 0; i < s.size(); i++){
            result += s[i];
        }

        string res;
        bool flag = false;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] != '0') {
                res.push_back(result[i]);
                flag = true;
            } else if (flag) {
                res.push_back(result[i]);
            }
        }
        if (!flag) res.push_back('0');

        return res;
    }


};

int main()
{
    string a;
    Solution s;
    int b[] = {0,0,55,11};
    vector<int> nums(b, b + sizeof(b) / sizeof(int));

//    for(int i = 0; i < nums.size(); i++){
//        cout<<nums[i]<<endl;
//    }
    a = s.minNumber(nums);
    cout<<a<<endl;
}
