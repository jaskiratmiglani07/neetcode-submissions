class Solution {
public:
    int solve(int i, bool holding, vector<int>&prices, vector<vector<int>> &dp){
        if(i > prices.size()-1){
            return 0;
        }
        if(dp[i][holding] != -1)
            return dp[i][holding];
        int buy, skip;
        int sell, hold;
        if(!holding){
            buy = -prices[i] + solve(i+1, true, prices, dp);
            skip = solve(i+1, false, prices, dp);
            return dp[i][holding] = max(buy, skip);
        }else{
            sell = prices[i] + solve(i+2, false, prices, dp);
            hold = solve(i+1, true, prices, dp);
            return dp[i][holding] = max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, false, prices, dp);
    }
};
