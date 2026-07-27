class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(idx >= coins.size()) return INT_MAX;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        //choose
        int take = INT_MAX;
        int not_take = INT_MAX;
        if((amount - coins[idx] )>= 0){
            take = 1 + ((solve(idx, coins, amount - coins[idx], dp) != INT_MAX) ? solve(idx, coins, amount - coins[idx], dp) : INT_MAX - 1);
        }
        //don't choose
        not_take = solve(idx + 1, coins, amount, dp);
        return dp[idx][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
//for every coin, we have the choice of choosing it or not choosing it, if we choose it, we can still choose it again
        vector<vector<int>>dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int res = solve(0, coins, amount, dp);     
        if(res != INT_MAX)
        return res;
        return -1;
    }
};
