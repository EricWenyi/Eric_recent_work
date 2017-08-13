//
//  main.cpp
//  ReverseBits
//
//  Created by 邬文弈 on 2017/8/13.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        
        for(int i = 0; i < 32; i++, n >>= 1){
            m <<= 1;
            m |= n & 1;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
