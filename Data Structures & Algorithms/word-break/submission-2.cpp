class Solution {
public:
    unordered_set<string>st;
    int maxLen = -1;
    int n;
    bool solve(int idx, string &s, vector<int>& dp){
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx];
        if(st.find(s.substr(idx)) != st.end()) return true;
        for(int l = 1; l <= maxLen; l++){
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(idx + l, s, dp)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        vector<int>dp(s.size(), -1);
        for(auto &x : wordDict){
            st.insert(x);
            maxLen = max(maxLen, int(x.size()));
        }
        return solve(0, s, dp);
    }
};
