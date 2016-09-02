#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0){
            return 0;
        }

        int counter = 0;
        int i;
        for( i = s.size() - 1; i >= 0 && s[i] == ' '; i--){//eliminate all the ' ' in the back
             ;
        }

        if(i == -1){
            return 0;
        }

        for(int j = i; j >= 0; j--){
            if(s[j] == ' '){
                break;
            }
            else{
                counter++;
            }
        }

        return counter;
    }
};

int main()
{
    string s = "                        thi                             ";
    Solution p;
    int n = p.lengthOfLastWord(s);
    cout<<n<<endl;
}
