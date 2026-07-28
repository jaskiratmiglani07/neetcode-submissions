class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
//i have two choices for every index, i can either choose it for creating my target sum or not choose it
        if(target == 0) return true;
        if(target < 0) return false;
        if(i >= nums.size()) return false;
        if(dp[i][target] != -1) return dp[i][target];
        if(solve(i + 1, target - nums[i], nums, dp) || solve(i + 1, target, nums, dp)) return true;
        return dp[i][target] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x : nums){
            sum += x;
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(target + 1, -1));
        return solve(0, target, nums, dp);
    }
};
