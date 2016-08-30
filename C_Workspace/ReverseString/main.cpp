#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string results = "";

        for(int i = s.size() - 1; i >= 0; i--){
            results += s[i];
        }


        return results;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseString("Hello");
}
