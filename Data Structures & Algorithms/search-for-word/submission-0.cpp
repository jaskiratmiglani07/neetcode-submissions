class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool found(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        if(idx == word.length()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '#' || board[i][j] != word[idx]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        for(auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            if(found(x, y, idx + 1, board, word)) {
                return true;
            }
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0] && found(i, j, 0, board, word)) {
                    return true;
                }
            }
        }   
        return false;
    }
};