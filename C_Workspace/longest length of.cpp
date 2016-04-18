class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        const int MAX = 127;
        int start = 0;
        int appearance[MAX];
        int max_length = 0;

        for (i = 0; i<MAX;i++){
        	appearance[i] = -1;
        }

        for (i = 0; i<s.size();i++){
        	if(appearance[s[i]] >= start){
        		max_length = max((int)i - start, max_length);
        		start = appearance[s[i]] +1;
        	}

        	appearance[s[i]] = i;
        }
        
        max_length = max((int)s.size() - start, max_length);

        return max_length;

    }
};