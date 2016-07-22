#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num == 0){
            return 0;
        }
        stack<int> bits;
        int n = 1;

        while(n <= num){
            int bit;
            bit = (num / n) % 10;
            bits.push(bit);
            n *= 10;
        }
        string s = "";

        while(!bits.empty()){
            int bit = bits.top();

            if(bits.size() == 4){
                if(bit == 3){
                    s.append("MMM");
                }
                else if(bit == 2){
                    s.append("MM");
                }
                else if(bit == 1){
                    s.append("M");
                }
            }

            if(bits.size() == 3){
                switch(bit){
                    case 1: s.append("C");break;
                    case 2: s.append("CC"); break;
                    case 3: s.append("CCC"); break;
                    case 4: s.append("DC"); break;
                    case 5: s.append("D"); break;
                    case 6: s.append("DC"); break;
                    case 7: s.append("DCC"); break;
                    case 8: s.append("DCCC"); break;
                    case 9: s.append("CM"); break;
                }
            }

            if(bits.size() == 2){
                switch(bit){
                    case 1: s.append("X"); break;
                    case 2: s.append("XX"); break;
                    case 3: s.append("XXX"); break;
                    case 4: s.append("XL"); break;
                    case 5: s.append("L"); break;
                    case 6: s.append("LX"); break;
                    case 7: s.append("LXX"); break;
                    case 8: s.append("LXXX"); break;
                    case 9: s.append("XC"); break;
                }
            }

            if(bits.size() == 1){
                switch(bit){
                    case 1: s.append("I"); break;
                    case 2: s.append("II"); break;
                    case 3: s.append("III"); break;
                    case 4: s.append("IV"); break;
                    case 5: s.append("V"); break;
                    case 6: s.append("VI"); break;
                    case 7: s.append("VII"); break;
                    case 8: s.append("VIII"); break;
                    case 9: s.append("IX"); break;
                }
            }

            bits.pop();
        }

        return s;
    }
};

int main()
{
    Solution s;
    string sl = s.intToRoman(1);
    cout<<sl<<endl;
}
