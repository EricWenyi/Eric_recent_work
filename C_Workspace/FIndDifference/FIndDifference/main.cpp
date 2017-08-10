//
//  main.cpp
//  FIndDifference
//
//  Created by 邬文弈 on 2017/8/10.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        if(t == "")
            return NULL;
        int a[26] = {0};
        int b[26] = {0};
        
        for(auto i = 0; i < s.size(); i++){
            a[s[i] - 97]++;
        }
        
        for(auto i = 0; i < t.size(); i++){
            b[t[i] - 97]++;
        }
        
        for(auto i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return i+97;
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution one;
    string s = "abc", t = "aebc";
    
    cout<<one.findTheDifference(s, t);
}
