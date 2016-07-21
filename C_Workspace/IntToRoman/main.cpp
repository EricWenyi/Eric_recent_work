#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num == 0){
            return 0;
        }
        stack<int> bits;
        int n = 1;

        while(n < num){
            int bit;
            bit = (num / n) % 10;
            bits.push(bit);
            n *= 10;
        }
        string s = "";


    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
