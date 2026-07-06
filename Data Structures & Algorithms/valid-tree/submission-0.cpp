class Solution {
public:
    void dfs(int node, vector<vector<int>> & adj, vector<bool>& vis){
        vis[node] = true;
        for(auto nei : adj[node]){
            if(!vis[nei]){
                dfs(nei, adj, vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int ne = edges.size();
        if(ne != n - 1) return false;
        vector<vector<int>>adj(n);
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n, false);
        dfs(0, adj, vis);
        for(auto x : vis){
            if(x == false){
                return false;
            }
        }
        return true;
    }
};
