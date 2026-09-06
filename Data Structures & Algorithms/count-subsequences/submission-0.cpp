#include<cstring>
class Solution {
public:
    string ass;
    string tee;
    int m, n;
    int dp[1005][1005];
    int solve(int i, int j){
        if(j >= n) return 1;
        if(i >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int skip = 0;
        int take = 0;
        if(ass[i] == tee[j]){
            take = solve(i + 1, j + 1);
            skip = solve(i + 1, j);
        }else{
            skip = solve(i + 1, j);
        } 
        return dp[i][j] = skip + take;
    }
    int numDistinct(string s, string t) {
        ass = s;
        tee = t;
        m = ass.size();
        n = tee.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};