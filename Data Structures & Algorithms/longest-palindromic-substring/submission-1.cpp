class Solution {
public:
    int maxLen = 0;
    bool solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= j) return true;
        if(s[i] == s[j]){
            return solve(i + 1, j - 1, s, dp);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string result;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s, dp)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
};
