//
//  main.cpp
//  AverageFromDataStream
//
//  Created by 邬文弈 on 2017/7/16.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<double> sum;
    int id,size;
    
    MovingAverage(int size) : sum(size, 0){
        id = 0;
        this->size = size;
    }
    
    int mod(int x){
        return x % size;
    }
    
    
    double next(int val) {
        // Write your code here
        if(id == 0){
            sum[id] = val;
            id++;
            return val;
        }
        
        int temp = sum[mod(id)];
        sum[mod(id)] = sum[mod(id-1)] + val;
        id++;
        if(id <= size){
            return sum[mod(id-1)] / id;
        }
        else{
            return (sum[mod(id-1)] - temp) / size;
        }
        
        
    }
};


int main(int argc, const char * argv[]) {
    MovingAverage *m = new MovingAverage(3);
    
    int res;
    res = m->next(1);
    cout<<res<<endl;
    
    res = m->next(3);
    cout<<res<<endl;
    
    res = m->next(5);
    cout<<res<<endl;
    
    res = m->next(7);
    cout<<res<<endl;
}




























