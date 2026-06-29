class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
// the first row and column are reachable by pacific and the last row and last column are reachable by atlantic
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>vis1(m, vector<int>(n, 0));
        vector<vector<int>>vis2(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {
            {-1, 0}, // up
            {1, 0},  // down
            {0, -1}, // left
            {0, 1}   // right
        };
        vector<vector<bool>> pacVis(m, vector<bool>(n, false));
        queue<pair<int, int>>q;
        for(int i = 0; i < m; i++){
            vis1[i][0] = 1;
            pacVis[i][0] = true;
            q.push({i, 0});
        }
        for(int j = 0; j < n; j++){
            vis1[0][j] = 1;
            pacVis[0][j] = true;
            q.push({0, j});
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto [dr, dc] : dir){
                int nr = row + dr;
                int nc = col + dc;
                if(nr > -1 && nr < m && nc > -1 && nc < n && !vis1[nr][nc]){
                    if(heights[nr][nc] >= heights[row][col]){
                        vis1[nr][nc] = 1;
                        pacVis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        vector<vector<bool>> atlVis(m, vector<bool>(n, false));
        queue<pair<int, int>>t;
        for(int i = 0; i < m; i++){
            vis2[i][n - 1] = 1;
            atlVis[i][n - 1] = true;
            t.push({i, n - 1});
        }
        for(int j = 0; j < n; j++){
            vis2[m - 1][j] = 1;
            atlVis[m - 1][j] = true;
            t.push({m - 1, j});
        }
        while(!t.empty()){
            int row = t.front().first;
            int col = t.front().second;
            t.pop();
            for(auto [dr, dc] : dir){
                int nr = row + dr;
                int nc = col + dc;
                if(nr > -1 && nr < m && nc > -1 && nc < n && !vis2[nr][nc]){
                    if(heights[nr][nc] >= heights[row][col]){
                        vis2[nr][nc] = 1;
                        atlVis[nr][nc] = true;
                        t.push({nr, nc});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacVis[i][j] && atlVis[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
