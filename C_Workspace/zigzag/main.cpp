#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
            int pattern = numRows*2 - 2;
            int period = s.size() / pattern;
            int remainder = s.size() % pattern;

            int Lines = period * (numRows - 1);

            if(remainder <= numRows){
                Lines++;
            }
            else{
                Lines += Lines + (remainder - numRows + 1);
            }

            char zigzag[numRows][Lines] = {{'0'}};

            bool flag = false;//a flag showing whether we need to reverse the string

            int i = 0;
            int j = 0;

            for(int k = 0; k < s.size(); k++){
                if(!flag){
                    zigzag[i][j] = s[k];

                    if(i >= numRows-1){
                            flag = true;
                            j++;
                            i--;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    zigzag[i][j] = s[k];

                    if(i == 0){
                        flag = false;
                        j++;
                    }
                    else{
                        i--;
                        j++;
                    }
                }
            }

            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < Lines; j++){
                    cout<<zigzag[i][j]<<" ";
                }
                cout<<endl;
            }
            //To be modified
            return s;
    }
};

int main()
{
    string s = "ASPISNET";
    Solution solu;
    solu.convert(s,3);
    return 0;
}
