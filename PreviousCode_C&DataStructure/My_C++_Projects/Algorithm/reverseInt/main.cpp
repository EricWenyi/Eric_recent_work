#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const int max = 0x7fffffff;  //MAX value of int
const int min = 0x80000000;
class Solution {
public:
    int reverse(int x) {

        if(x == 0)
            return 0;

        queue<int> s;

        while(x != 0){
            int digit = x % 10;
            s.push(digit);
            x = x / 10;
        }


        long long y = 0;
        while(!s.empty()){
            y = y * 10 + s.front();
            s.pop();
        }
        if (y > max || y < min){
            return 0;
        }

        return y;
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(1534236469);
    return 0;
}
