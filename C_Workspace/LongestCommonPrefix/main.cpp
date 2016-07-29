#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //this is way 1, the easiest and most stupid way. However I do believe it could perform well.
        string s = "";

        if(strs.size() == 0)
            return s;
        else if(strs.size() == 1){
            return strs[0];
        }

        int MIN_LENGTH = INT_MAX;
        for(size_t i = 0; i < strs.size(); i++){
            if(strs[i].size() < MIN_LENGTH){
                MIN_LENGTH = strs[i].size();
            }
        }
        //cout<<MIN_LENGTH<<endl;

        char common;

        for(int i = 0; i < MIN_LENGTH; i++){
            common = strs[0][i];
            for(size_t j = 0; j < strs.size(); j++){

                if(strs[j][i] != common){
                    cout<<j<<endl;
                    if(i == 0){
                        return s;
                    }
                    else{
                        s = strs[j];
                        s = s.substr(0,i);
                        //cout<<s;
                        return s;
                    }
                }
            }
        }

        s = strs[0];
        s = s.substr(0,MIN_LENGTH);
        return s;


    }
};

int main()
{
    Solution s;
    string s1,s2,s3;
    s1 = "abcd";
    s2 = "abcde";
    s3 = "abc";
    vector<string> str;
    str.push_back(s1);
    str.push_back(s2);
    str.push_back(s3);
    cout<<s.longestCommonPrefix(str);
}
