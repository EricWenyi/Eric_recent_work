#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string result = "";
        if(s.empty())
            return result;
        int i = 0;
        for( i = s.size() - 1; i >= 0 && s[i] == ' '; i--){
            ;
        }
        int back = i + 1;
        int front = i;

        while(front >= 0){
            while(s[front] != ' ' && front >= 0){
                front--;
            }
            for(int i = front + 1; i <back; i++){
                result += s[i];
            }
            if(s[front] == ' ')
                result += ' ';
            back = front;
            front--;
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseWords("ASA SAS");

}
