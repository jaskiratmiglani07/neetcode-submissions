class Solution {
public:
    int solve(int i, int sum, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(sum == amount){
            return 1;
        }
        if(i >= coins.size())
            return 0;
        if(sum > amount)
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int take = 0;
        int not_take = 0;
        if(sum < amount){
            take = solve(i, sum + coins[i], amount, coins, dp);
            not_take = solve(i + 1, sum, amount, coins, dp);
        }
        else
        not_take = solve(i + 1, sum, amount, coins, dp);
        return dp[i][sum] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ways = solve(0, 0, amount, coins, dp);
        return ways;
    }
};
