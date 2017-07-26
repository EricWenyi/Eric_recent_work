//
//  main.cpp
//  CheckWordAbbr
//
//  Created by 邬文弈 on 2017/7/25.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


class Solution {
public:
    /**
     * @param word a non-empty string
     * @param abbr an abbreviation
     * @return true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string& word, string& abbr) {
        // Write your code here
        int length = 0;
        int lenOfNum = 0;
        for(int i = 0, j = 0; i < abbr.size() && j < word.size(); i++, j++){
            if(word[i] != abbr[j]){
                if(abbr[j]>48 && abbr[j] < 58){
                    
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
    

    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    
    
    string word = "iauiuiauruwaioushfjsahfjahwuewhdjahsjdhjwaeiuwjdajskdjshajeuiwdsjkahjdhasjdhkjw";
    string abbr = "iauiuiauruwaioushfj13jahsjdhjwaeiuwjd1js1d1shajeuiwdsjkahjdhasjdhkjw";
    
    cout<<s.validWordAbbreviation(word, abbr)<<endl;;
    
    
}
