#include<cstring>
class Solution {
public:
    vector<int>num;
    int dp[1001][2005];
    int solve(int i, int prev){
        if(i == num.size()) return 0;
        if(dp[i][prev + 1001] != -1) return dp[i][prev + 1001];
        int skip = 0;
        int take = 0;
        if(prev == -1001 || num[i] > prev){
            take = 1 + solve(i + 1, num[i]);          
        }
        skip = solve(i + 1, prev);
        return dp[i][prev + 1001] = max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        num = nums;
        memset(dp, -1, sizeof(dp));
        return solve(0, -1001);    
    }
};
