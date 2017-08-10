//
//  main.cpp
//  ConvertNumberToHexadecimal
//
//  Created by 邬文弈 on 2017/8/10.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        string HEX = "0123456789abcdef";
        int counter = 0;
        string result;
        
        while(num && counter++ < 8){
            result = HEX[num & 0xf] + result;
            num >>= 4;
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.toHex(-1)<<endl;
    
}
