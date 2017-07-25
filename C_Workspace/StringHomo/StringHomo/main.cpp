//
//  main.cpp
//  StringHomo
//
//  Created by 邬文弈 on 2017/7/24.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s
     * can be replaced to get t or false
     */
    bool isIsomorphic(string& s, string& t) {
        // Write your code here
        if(s.size() != t.size())
            return false;
        
        vector<int> map(256,0);
        for(int i = 0; i < s.size(); i++){
            if(map[s[i]] == 0){
                map[s[i]] = t[i];
            }
            else if(map[s[i]] != t[i]){
                return false;
            }
            
        }
        
        vector<int> project(256,0);
        
        for(int i = 0; i < t.size(); i++){
            if(project[t[i]] == 0){
                project[t[i]] = s[i];
            }
            else if (project[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
