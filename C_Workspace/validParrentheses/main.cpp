#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isValid(string s) {
            if(s.size() == 0){
                return false;
            }

            if(s.size() % 2){
                return false;
            }

            stack<char> parenthses;

            for(size_t i = 0; i < s.size(); i++){
                if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                        parenthses.push(s[i]);
                }
                else if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
                    if(parenthses.size() == 0){
                        return false;
                    }
                    else{
                        char match = parenthses.top();

                        if(s[i] - 1 != match && s[i] - 2 != match){
                            return false;
                        }
                        parenthses.pop();
                    }

                }
            }
            if(parenthses.size() == 0){
                return true;
            }
            else{
                return false;
            }


    }
};
int main()
{
    Solution o;
    string s = "[]";

    if(o.isValid(s)){
        cout<<"This is me"<<endl;
    }

    return 0;
}
