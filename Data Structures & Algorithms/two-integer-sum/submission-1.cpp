class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>id;
        for(int i = 0; i < nums.size(); i++){
            id[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(id.find(target - nums[i]) != id.end() && id[target - nums[i]] != i) return vector<int>{i, id[target - nums[i]]};
        }        
    }
};
