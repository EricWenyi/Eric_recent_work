//
//  main.cpp
//  NumberCompletion
//
//  Created by 邬文弈 on 2017/8/2.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        mask = ~mask;
        while(mask & num){
            mask = mask << 1;
        }
        
        return ~mask & ~num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
