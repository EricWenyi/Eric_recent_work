#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
            if(numRows == 0 || numRows == 1){
                return s;
            }
            if(s.empty()){
                return s;
            }

            int pattern = numRows*2 - 2;
            int period = s.size() / pattern;
            int remainder = s.size() % pattern;

            //cout<<pattern<<" "<<period<<" "<<remainder<<endl;;

            int Lines = period * (numRows - 1);

            //cout<<Lines<<endl;

            if(remainder <= numRows && remainder>0){
                Lines++;
            }
            else if (remainder > numRows && remainder < pattern){
                Lines += Lines + (remainder - numRows + 1);
            }

            //cout<<Lines<<endl;

            char zigzag[numRows][Lines];

            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < Lines; j++){
                    zigzag[i][j] = '0';
                }
            }



            bool flag = false;//a flag showing whether we need to reverse the string

            int i = 0;
            int j = 0;

            for(size_t k = 0; k < s.size(); k++){
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
                        i++;
                    }
                    else{
                        i--;
                        j++;
                    }
                }
            }

            char * new_s = new char[s.size()];

//            for(int i = 0; i < numRows; i++){
//                for(int j = 0; j < Lines; j++){
//                   cout<<zigzag[i][j]<<" ";
//                }
//                cout<<endl;
//            }
            int k = 0;
            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < Lines; j++){
                    if(zigzag[i][j] != '0'){
                        new_s[k] = zigzag[i][j];
                        k++;
                    }
                }
            }
            //cout<<new_s[0]<<endl;
            //To be modified
            string b(new_s,s.size());
            return b;
    }
};

int main()
{
    string s = "A";
    string b;
    Solution solu;
    b = solu.convert(s,1);
    cout<<b;
    return 0;
}
