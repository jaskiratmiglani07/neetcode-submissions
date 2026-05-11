class Solution {
public:
    int solve(int i, int sum, vector<int>&nums, int target, int total, vector<vector<int>>&dp){
        int n = nums.size();
        if(i == n-1){
            return (sum + nums[i] == target) + (sum - nums[i] == target);
        }
        if(dp[i][sum + total] != -1)
            return dp[i][sum + total];
        int way1 = solve(i+1, sum + nums[i], nums, target, total, dp);
        int way2 = solve(i+1, sum - nums[i], nums, target, total, dp);
        return dp[i][sum + total] = way1 + way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++)
            total += nums[i];
        vector<vector<int>>dp(nums.size(), vector<int>(2*total + 1, -1));
        int result = solve(0, 0, nums, target, total, dp);
        return result;
    }
};
