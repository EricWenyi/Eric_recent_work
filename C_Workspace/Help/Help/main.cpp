//
//  main.cpp
//  Help
//
//  Created by 邬文弈 on 2017/8/9.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>

using namespace std;

class Vector {
    

private:
    unsigned int size;
    int * buffer;
    
    
public:
    Vector();
    
    Vector(unsigned int length){
        size = length;
        buffer = new int[size];
    }

    ~Vector(){
        delete[] buffer;
    }
    
    Vector & operator + (const Vector & v){
        
        for(int i = 0; i < size; i++){
            buffer[i] = buffer[i] + v.buffer[i];
        }
        
        return *this;
    }
    
    Vector & operator = (const Vector& v){
        delete[] buffer;
        size = v.size;
        buffer = new int[size];
        for (int i = 0; i < size; i++){
            buffer[i] = v.buffer[i];
        }
        return *this;
    }
    
    
    Vector & operator += (const Vector & v){
        
        for(int i = 0; i < size; i++){
            buffer[i] += v.buffer[i];
        }
        
        return *this;
    }
    
    int& operator [] (unsigned int index){
        return buffer[index];
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    Vector v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    
    Vector v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    
    Vector v3(3);
    
    v3 = v1 + v2;
    cout<<v3[0];
    return 0;
}


















