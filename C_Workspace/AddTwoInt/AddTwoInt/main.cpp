//
//  main.cpp
//  AddTwoInt
//
//  Created by 邬文弈 on 2017/8/13.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        bool flag = false;
        
        for(int i = 0; i < 32; i++, res <<= 1){
            if(!flag){
                if((a & 1) ^ (b & 1)){
                    res |= 1;
                }
                else{
                    if(a & 1){
                        flag = true;
                    }
                }
            }
            else{
                if(!((a & 1) ^ (b & 1))){
                    if(a & 1){
                        res |= 1;
                    }
                    else{
                        res |= 1;
                        flag = false;
                    }
                }
            }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
}
