#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int smallerNumber(int a, int b, int c){
        if(a <= b && a <= c){
            return a;
        }
        else if(b <= a && b <= c){
            return b;
        }
        else
            return c;
    }

    int nthUglyNumber(int n) {
        // write your code here
        if(n == 1){
            return 1;
        }

        vector<int> uglynumbers;
        int counter = 0;

        uglynumbers.push_back(1);
        counter++;

        int pointer2 = 0;
        int pointer3 = 0;
        int pointer5 = 0;

        while(counter < n){
            //cout<<"counter: "<<counter<<" ";
            int greatest = uglynumbers[counter-1];
            //cout<<"greatest: "<<greatest<<" ";

            while( (uglynumbers[pointer2] * 2) <= greatest ) pointer2++;
            while( (uglynumbers[pointer3] * 3) <= greatest ) pointer3++;
            while( (uglynumbers[pointer5] * 5) <= greatest ) pointer5++;


            int smallerNum = smallerNumber(uglynumbers[pointer2] * 2, uglynumbers[pointer3] * 3, uglynumbers[pointer5] * 5);
            //cout<<"smallerNUm: "<<smallerNum<<" "<<endl;
            uglynumbers.push_back(smallerNum);
            counter++;
        }

        return uglynumbers[n - 1];
    }
};

int main()
{
    Solution s;
    int res = s.nthUglyNumber(9);
    cout<<res<<endl;

    return 0;
}
