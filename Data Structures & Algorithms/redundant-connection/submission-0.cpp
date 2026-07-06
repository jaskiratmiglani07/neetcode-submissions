class Solution {
public:
    bool dfs(int node, int target, vector<vector<int>>& adj, vector<bool>& vis){
        if(node == target){
            return true;
        }
        vis[node] = true;
        for(auto nei : adj[node]){
            if(!vis[nei] && dfs(nei, target, adj, vis)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            vector<bool>vis(n + 1, false);
            if(dfs(u, v, adj, vis)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
