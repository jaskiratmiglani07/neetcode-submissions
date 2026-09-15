class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    // void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vis[row][col] = 1;
    //     queue<pair<int, int>>q;
    //     q.push({row, col});
    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();
    //         int delrow[] = {-1, 0, 1, 0};
    //         int delcol[] = {0, 1, 0, -1};
    //         for(int i = 0; i < 4; i++){
    //             int nrow = row + delrow[i];
    //             int ncol = col + delcol[i];
    //             if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
    //                 vis[nrow][ncol] = 1;
    //                 q.push({nrow, ncol});
    //             }
    //         }
    //     }
    // }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, vis, grid);
                    island += 1;
                }
            }
        }
        return island;
    }
};