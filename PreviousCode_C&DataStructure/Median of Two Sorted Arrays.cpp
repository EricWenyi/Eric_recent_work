class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int * p1 = nums1;
        int * p2 = nums2;
        int counter = 0;

        if((m+n)%2 == 1){
        	int threshold = (m+n+1)/2;

        	
        } 
        else{
        	int threshold = (m+n)/2;
        }


    }
};