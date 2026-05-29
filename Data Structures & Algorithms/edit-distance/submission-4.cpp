class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        }
        int replace, insert, del;
        replace = 1 + solve(i + 1, j + 1, word1, word2, dp);
        insert = 1 + solve(i, j+1, word1, word2, dp);
        del = 1 + solve(i + 1, j, word1, word2, dp);
        return dp[i][j] = min(replace, min(insert, del));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // int ans = solve(0, 0, word1, word2, dp);
        // vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        // for(int j = 0; j < m + 1; j++) dp[n][j] = m - j;
        // for(int i = 0; i < n + 1; i++) dp[i][m] = n - i;
        // for(int i = n - 1; i >= 0; i--){
        //     for(int j = m - 1; j >= 0; j--){
        //         if(word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];
        //         else{
        //         int replace = 1 + dp[i + 1][j + 1];
        //         int insert = 1 + dp[i][j + 1];
        //         int del = 1 + dp[i + 1][j];
        //         dp[i][j] = min(replace, min(insert, del));}
        //     }
        // }
        // return dp[0][0];
        vector<int>curr(m + 1);
        vector<int>next(m + 1);
        for(int j = 0; j <= m; j++) next[j] = m - j;
        for(int i = n - 1; i >= 0; i--){
            curr[m] = n - i;
            for(int j = m - 1; j >= 0; j--){
                if(word1[i] == word2[j]) curr[j] = next[j + 1];
                else{
                int replace = 1 + next[j + 1];
                int insert = 1 + curr[j + 1];
                int del = 1 + next[j];
                curr[j] = min(replace, min(insert, del));}
            }
            next = curr;
        }
        return next[0];
    }
};
