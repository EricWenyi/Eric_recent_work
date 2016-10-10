#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        vector<string> luyun;
        string results;

        for(size_t i = 0; i < nums.size(); i++){//convert int to strings
            string temp;
            itoa(nums[i], temp, 10);
        }

        vector<int> order;
        int max_length = 0;

        for(size_t i = 0; i < nums.size(); i++){//get the max length
            if(nums[i].size() > max_length){
                max_length = nums[i].size();
            }
        }

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
