#include<cstring>
class Solution {
public:
    string st;
    int dp[101];
    int solve(int i){//number of ways to map the string in valid groups of 1 and 2
        if(i >= st.size()) return 1;
        if(dp[i] != -1) return dp[i];
        int ways = 0;
        if(st[i] != '0'){
            ways += solve(i + 1);
        } 
        if(i + 1 < st.size( ) && ((st[i] == '1' && st[i + 1] <= '9') || (st[i] == '2' && st[i + 1] <= '6'))) {
            ways += solve(i + 2);
        }   
        return dp[i] = ways;                           
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        st = s;
        return solve(0);
    }
};
//10 to 26