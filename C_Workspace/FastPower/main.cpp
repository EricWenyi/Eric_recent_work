#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n == 1){
            return a % b;
        }
        if(n == 0){
            return 1 % b;
        }

        long product;

        product = fastPower(a,b,n/2);
        product = (product * product) % b;

        if(n % 2 == 1)
            product = (product * a) % b;

        return product;
    }
};

int main()
{
    int a = 3;
    int b = 5;
    int n = 3;

    Solution s;
    cout<<s.fastPower(a,b,n);
}
