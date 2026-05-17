class Solution {
public:
    int dfs(int i , int j, vector<vector<int>>&grid, vector<vector<int>>&visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = 1;
        int ans = 1;
        int delrow[4] = {-1, 0, 0, 1};
        int delcol[4] = {0, -1, 1, 0};
        for(int k = 0; k < 4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if(nrow < m && nrow > -1 && ncol < n && ncol > -1 && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                ans += dfs(nrow, ncol, grid, visited);
            }
        }
        return ans;
    }
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1;
        visited[i][j] = 1;
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int>curr = q.front();
            q.pop();
            int delrow[4] = {-1, 0, 0, 1};
            int delcol[4] = {0, -1, 1, 0};
            for(int k = 0; k < 4; k++){
                int nrow = curr.first + delrow[k];
                int ncol = curr.second + delcol[k];
                if(nrow < m && nrow > -1 && ncol < n && ncol > -1 && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    ans++;
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }            
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    maxi = max(dfs(i, j, grid, visited), maxi);
                }
            }
        }
        return maxi;
    }
};
