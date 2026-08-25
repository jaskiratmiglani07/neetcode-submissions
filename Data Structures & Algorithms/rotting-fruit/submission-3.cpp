class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        vector<pair<int,int>> dir = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1}
        };
        // for(auto x : dir){
        //     cout << x.first << " " << x.second << " ";
        // }
        // cout << endl;
        int t = 0;
        while(!q.empty()){
            int s = q.size();
            cout << "s : " << s << endl;
            while(s--){
                auto x = q.front();
                int r = x.first;
                int c = x.second;
                q.pop();
                for(auto &delta : dir){
                    int nr = r + delta.first;
                    int nc = c + delta.second;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            if(q.size() != 0)
            t++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return t;
    }
};
