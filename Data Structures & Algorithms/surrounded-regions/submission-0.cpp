class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>safe(m, vector<int>(n, 0));      
        vector<pair<int, int>> dir = {
            {-1, 0}, // up
            {1, 0},  // down
            {0, -1}, // left
            {0, 1}   // right
        };
        queue<pair<int, int>>q;
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                safe[0][j] = 1;
                q.push({0, j});
            }
            if(board[m - 1][j] == 'O'){
                safe[m - 1][j] = 1;
                q.push({m - 1, j});
            }
        } 
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                safe[i][0] = 1;
                q.push({i, 0});
            }
            if(board[i][n - 1] == 'O'){
                safe[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        } 
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto [dr, dc] : dir){
                int nr = row + dr;
                int nc = col + dc;
                if(nr > -1 && nr < m && nc > -1 && nc < n && !safe[nr][nc] && board[nr][nc] == 'O'){
                    safe[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !safe[i][j]){
                    board[i][j] = 'X';
                }
            }
        }         
    }
};
