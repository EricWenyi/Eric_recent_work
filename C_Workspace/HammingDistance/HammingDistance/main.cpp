//
//  main.cpp
//  HammingDistance
//
//  Created by 邬文弈 on 2017/7/27.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int counter = 0;
        for(int i = 0; i < 32; i++){
            if(res % 2)
                counter++;
            
            res = res>>1;
        }
        
        return counter;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 1;
    int y = 4;
    
    Solution s;
    cout<<s.hammingDistance(x, y)<<endl;
}
