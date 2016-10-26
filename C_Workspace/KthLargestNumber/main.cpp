#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        typedef multiset<int> intset;
        typedef multiset<int>::iterator setIterator;

        intset leastnumbers;

        vector<int>::iterator vec_iterator;
        vec_iterator = nums.begin();

        for( ;vec_iterator != nums.end(); vec_iterator++){
            if(leastnumbers.size() < k){
                leastnumbers.insert(*vec_iterator);
            }
            else{
                setIterator greatest = leastnumbers.begin();

                if((*vec_iterator) > (*greatest)){
                    leastnumbers.erase(greatest);
                    leastnumbers.insert(*vec_iterator);
                }
            }

        }

        setIterator result;
        result = leastnumbers.begin();
        return (*result);
    }
};

int main()
{
    int a[] = {1,2,3,4,5,6};
    vector<int> nums(a,a + sizeof(a) / sizeof(int));

    Solution s;
    int res = s.kthLargestElement(3,nums);

    cout<<res<<endl;
    return 0l;
}
