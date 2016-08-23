#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.empty() && needle.empty()){
            return 0;
        }
        else if(haystack.empty() && !needle.empty()){
            return -1;
        }
        else if(!haystack.empty() && needle.empty()){
            return 0;
        }
        if(needle.size() > haystack.size()){
            return -1;
        }

        bool same = true;

        //int h = 0; //h is the pointer to haystach
        //int n = 0; //n is the pointer to needle

        for(size_t i = 0; i <= haystack.size() - needle.size(); i++){

            if(haystack[i] == needle[0]){
                same = true;

                for(size_t j = 0; j < needle.size(); j++){
                    if(haystack[i + j] != needle[j]){
                        same = false;
                        break;
                    }
                }

                if(same){
                    return i;
                }
            }


        }

        return -1;

    }
};

int main()
{
    string haystack = "Thisisme";
    string needle = "me";

    Solution s;
    int n = s.strStr(haystack,needle);

    cout<<n<<endl;
}
