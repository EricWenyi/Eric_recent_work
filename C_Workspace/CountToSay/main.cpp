#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string GenerateSequence(string s){
        string results;
        size_t j = 0;

        for(size_t i = 0; i < s.size(); i++){
            if(s[i] != s[i+1]){
                results+= '1';
                results+= s[i];
            }
            else{
                for( j = i; j < s.size(); j++){
                    if(s[j] == s[j+1]){
                        ;
                    }
                    else{
                        break;
                    }
                }

                stringstream ss ;
                ss << (j - i + 1);
                string len = ss.str();
                results+= len;
                results+=s[i];
                i = j;
            }
        }

        return results;
    }

    string countAndSay(int n) {
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return "1";
        }

        string s = "1";
        for(int i = 1; i < n; i++){
            s = GenerateSequence(s);
            //cout<<s<<endl;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string resutls = s.countAndSay(5);
    //cout<<resutls<<endl;
}
