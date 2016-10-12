#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        vector<int> temp;
        long long results = 0;
        int length = A.size();
        temp.push_back(A[length - 1]);

        for(int i = A.size() - 2; i >= 0; i--){//binary search
            int left = 0;
            int right = temp.size();
            while(left < right){
                int mid = (left + right) / 2;
                if(A[i] > temp[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }

            temp.insert(temp.begin() + right, A[i]);
            results += right;
        }

        return results;
    }
};

using namespace std;

int main()
{
    vector<int> i;
    i.push_back(5);
    i.push_back(3);

    Solution s;
    long long res =  s.reversePairs(i);

    cout<<res;

    return 0;
}
