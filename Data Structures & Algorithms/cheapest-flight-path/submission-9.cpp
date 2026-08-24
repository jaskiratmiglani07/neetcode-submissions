#include <cstring>
class Solution {
public:
    unordered_map<int, vector<pair<int, int>>>adj;
    int dp[105][105];
    int dfs(int src, int dst, int k){
        if(src == dst && k >= 0) return 0;
        if(k < 0) return 1e9;
        if(dp[src][k] != -1) return dp[src][k];
        int ans = 1e9;
        for(auto &nei : adj[src]){
            int t = nei.second + dfs(nei.first, dst, k - 1);
            ans = min(ans, t);
        }
        return dp[src][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        // for(int i = 0; i < adj.size(); i++){
        //     cout << i << ": ";
        //     for(auto &x : adj[i]){
        //         cout << x.first << " " << x.second << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int res = dfs(src, dst, k + 1);
        return (res >= 1e9 ? -1 : res);
    }
};
