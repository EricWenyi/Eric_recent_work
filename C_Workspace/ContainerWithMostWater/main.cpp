#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;

        while(i < j){
            int max_height = min(height[i],height[j]);
            cout<<max_height<<endl;
            water = max(water, max_height * (j - i));

            while(i < j && height[i] <= max_height) i++;
            while(i < j && height[j] <= max_height) j--;
        }

        return water;
    }
};

int main()
{
    int myarr[] = {2,1};
    vector<int> height(myarr, myarr + sizeof(myarr) / sizeof(int));

    Solution s;

    cout<<s.maxArea(height);
}
