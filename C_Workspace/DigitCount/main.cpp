#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int temp = n;
        int length = 0;
        while(temp != 0){
            temp = temp / 10;
            length++;
        }

        return length;
    }
};

int main()
{
    int length;

    Solution s;
    length = s.digitCounts(2,49);
    cout<<length;

    return 0;
}
