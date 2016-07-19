#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int n1 = 1;

        while(x / n1 > 10){
            n1 *= 10;
        }
        cout<<n1<<endl;

        int n2 = 1;

        while(n1 >= n2){
            int head,tail;

            head = (x / n1) % 10;
            tail = (x / n2) % 10 ;

            if(head != tail){
                return false;
            }
            else{
                n1 /= 10;
                n2 *= 10;
            }
        }

        return true;

    }
};

int main()
{
    Solution s;
    int x = 12321;
    cout<<s.isPalindrome(12321)<<endl;
}
