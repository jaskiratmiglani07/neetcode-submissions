class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        vector<pair<int, int>>dir = {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };
        int sz = 0;
        int min = 0;
        while(!q.empty()){
            sz = q.size();
            bool rotted = false;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(auto x : dir){
                    int nr = r + x.first;
                    int nc = c + x.second;
                    if(nr < m && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        rotted = true;
                        q.push({nr, nc});
                    }
                }
            }
            if(rotted)
            min += 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return min;
    }
};
