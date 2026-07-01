class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, adj, visited, inRecursion))
                    return true;
            }
            else if (inRecursion[v]) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }        
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, inRecursion))
                    return false;      // cycle exists
            }
        }
        return true;                   // no cycle
    }
};
