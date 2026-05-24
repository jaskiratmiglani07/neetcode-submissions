class Solution {
public:
    bool solve(int i , int j , int k, int m, int n, int N, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(i == m && j == n && k == N) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < m && k < N && s1[i] == s3[k]){
            if(solve(i + 1, j, k + 1, m, n, N, s1, s2, s3, dp))
                return dp[i][j] = true;
        }
        if(j < n && k < N && s2[j] == s3[k]){
            if(solve(i, j + 1, k + 1, m, n, N, s1, s2, s3, dp))
                return dp[i][j] = true;          
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int N = s3.size();
        if(m + n != N) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        bool ans = solve(0, 0, 0, m, n, N, s1, s2, s3, dp);
        // aaa  aaa 
        return ans;
    }
};
