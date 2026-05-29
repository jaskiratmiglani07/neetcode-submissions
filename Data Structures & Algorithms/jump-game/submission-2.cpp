class Solution {
public:
    bool solve(int i, vector<int> & nums){
        if(i == nums.size() - 1) return true;
        bool ans = false;
        for(int j = 1; j <= nums[i]; j++){
            ans = solve(i + j, nums);
            if(ans) return true;
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        // bool ans = solve(0, nums);
        // return ans;
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(maxReach >= nums.size() - 1) return true;
            if(maxReach < i) return false;
            maxReach = max(maxReach, nums[i] + i);
        }
        return false;
    }
};
