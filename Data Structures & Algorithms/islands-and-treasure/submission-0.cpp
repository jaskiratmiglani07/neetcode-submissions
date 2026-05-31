class Solution {
public:
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                q.push({i, j});
            }
        }
        vector<pair<int,int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        while(!q.empty()){
            pair<int, int>jock = q.front();
            q.pop();
            int r = jock.first;
            int c = jock.second;
            for(auto d : dir){
                int nr = r + d.first;
                int nc = c + d.second;
                if(nr < m && nc < n && nr >= 0 && nc >= 0){
                    if(grid[nr][nc] == INF){
                        grid[nr][nc] = grid[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};
