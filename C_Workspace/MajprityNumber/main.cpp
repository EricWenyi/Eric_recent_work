#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if(nums.empty())
            return 0;
        size_t length = nums.size();

        map<int,int> m;
        map<int,int>::iterator it;

        for(size_t i = 0; i < nums.size(); i++){
            it = m.find(nums[i]);

            if(it != m.end()){
                (it->second)++;
                if(it->second > length / 2){
                        cout<<2<<endl;
                    return it->first;
                }
            }
            else{
                m[nums[i]] = 1;
            }
        }
        return it->first;


    }
};


int main()
{
    int a[] = {0};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));

    Solution s;
    int b = s.majorityNumber(nums);
    cout<<b<<endl;
}
