class Solution {
public:
    vector<pair<int, int>> dir = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        int n = matrix.size();
        int m = matrix[0].size();
        dp[i][j] = 1;
        for (auto [dx, dy] : dir) {
            int nr = i + dx;
            int nc = j + dy;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + solve(nr, nc, matrix, dp));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};