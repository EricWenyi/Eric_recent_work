//
//  main.cpp
//  EditDistance
//
//  Created by 邬文弈 on 2017/7/18.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string& s, string& t) {
        // Write your code here
        int len1 = s.size();
        int len2 = t.size();
        
        if(len1 == 0 && len2 == 0)
            return false;
        bool result = false;
        
        if(len1 - len2 == 0){
            result = changeCharacter(s,t,len1);
        }
        else if(len1 - len2 == 1){
            result = addCharacter(s, t, len1);
        }
        else if(len2 - len1 == 1){
            result = addCharacter(t, s, len2);
        }
        
        return result;
        
        
    }
    
    bool changeCharacter(string &s, string &t, int len) {
        int counter = 0;
        
        for(int i = 0; i < len && counter <2; i++){
            if(s[i] != t[i])
                counter += 1;
        }
        
        if (counter == 1)
            return true;
        else
            return false;
    }
    
    bool addCharacter(string &s, string &t, int len){
        bool flag = false;
        for(int i = 0; i < len ; i++){
            if (flag){
                if(s[i] != t[i-1])
                    return false;
            }
            else{
                if(i == len - 1)
                    return true;
                
                if(s[i] != t[i]){
                    flag = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string sa = "s";
    string ta = "s";
    cout<<s.isOneEditDistance(sa,ta)<<endl;
}






















