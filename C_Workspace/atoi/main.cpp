#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
            return 0;

        int i = 0;//wipe white space ahead of the sequence

        while(str[i] == ' '){
            i++;
        }

        int num = 0;
        bool flag = true;
        bool overflow = false;
        int  oldnum = 0;

        if(str[i] == '+')
            i++;
        else if(str[i] == '-'){
            flag = false;
            i++;
        }
        else if(str[i] >'9' || str[i] < '0'){
            return 0;
        }

        while(str[i] <= '9' && str[i] >= '0'){
            oldnum = num;
            num = num*10 + str[i] - '0';

            if(num/10 != oldnum){
                overflow = true;
            }

            i++;
        }
//        cout<<overflow<<endl;
//        cout<<oldnum<<endl;
//        cout<<num<<endl;

        if(overflow){
            if(flag){
                return INT_MAX;
            }
            else
                return INT_MIN;
        }

        if(!flag){
            num = -num;
        }

        return num;
    }
};

int main()
{
    Solution s;
    int num;
    string a = "    10522545459";
    num = s.myAtoi(a);
    cout<<num<<endl;
}
