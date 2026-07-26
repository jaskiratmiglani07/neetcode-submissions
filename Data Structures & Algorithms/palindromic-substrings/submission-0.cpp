class Solution {
public:
    bool solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= j) return true;
        if(s[i] == s[j]){
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s, dp)){
                    count++;
                }
            }
        }
        return count;
    }
};
