//
//  main.cpp
//  RotateNumbers
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
     * @param num a string
     * @return true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string& num) {
        int len = num.size();
        
        if(len == 0)
            return false;
        
        for(int i = 0; i <= len/2; i++){
            if (!isRotate(num[i],num[len-1-i])){
                
                return false;
            }
            
        }
        
        return true;
    }
    
    bool isRotate(char a, char b){
        if(a=='1'&& b=='1')
            return true;
        else if(a == '8' && b == '8')
            return true;
        else if(a == '6' && b == '9')
            return true;
        else if (a == '9' && b=='6')
            return true;
        else if (a == '0' && b == '0')
            return true;
        else
            return false;
    }
    
    
};

int main(int argc, const char * argv[]) {
    string a = "69";
    Solution s;
    cout<<s.isStrobogrammatic(a);
    return 0;
}
