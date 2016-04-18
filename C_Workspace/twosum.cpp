class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        int i = 0;
        for( i = 0; i< nums.size(); i++){
            map[nums[i]] = i;
        }
        
        for ( i = 0; i < nums.size(); i++){
            const int gap = target - nums[i];
            if (map.find(gap) != map.end() && map[gap] > i){
                result.push_back(i + 1);
                result.push_back(map[gap] + 1);
                break;
            }
        }
        
        return result;
    }
};