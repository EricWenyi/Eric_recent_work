#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if(A.size()%2 != 1)
            return 0;
        map<int,int> dic;
        for(int i = 0 ; i < A.size(); i++){
            dic[A[i]]++;
        }

        map<int,int>::iterator pos = dic.begin();

        for(;pos!=dic.end(); pos++){
            if(pos->second == 1)
                return pos->first;
        }
    }
};


int main()
{
    int a[] = {2,4,4};
    vector<int> A(a,a + sizeof(a) / sizeof(int));

    Solution s;
    cout<<s.singleNumber(A);
}
