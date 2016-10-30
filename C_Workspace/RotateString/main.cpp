#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void ReverseString(string &str,string::iterator start, string::iterator back){

        while(start < back){
            char temp;
            temp =  *start;
            *start = *back;
            *back = temp;
            back--;
            start++;
        }
    }

    void rotateString(string &str,int offset){
        //wirte your code here
        ReverseString(str, str.begin(), --str.end());

        string::iterator pos = str.begin();

        for(int i =0; i < offset; i++){
            pos++;
        }

        if(pos == str.begin()){
            ;
        }
        else
            --pos;

        ReverseString(str,str.begin(), pos);
        ReverseString(str, ++pos, --str.end());

        cout<<str<<endl;

    }
};


int main()
{
    Solution s;
    string str = "abcdefg";
    s.rotateString(str,2);

}
