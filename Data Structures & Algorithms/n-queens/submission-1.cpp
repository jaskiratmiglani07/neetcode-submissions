class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board){
        int n = board.size();
        for(int j = 0; j < board.size(); j++){
            if(board[row][j] == 'Q') return false;
        }
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int k = n; k >= 0; k--){
            if(row - k >= 0 && row - k < n && col - k >= 0 && col - k < n && board[row - k][col - k] == 'Q') return false;
            if(row + k >= 0 && row + k < n && col + k >= 0 && col + k < n && board[row + k][col + k] == 'Q') return false;
            if(row + k >= 0 && row + k < n && col - k >= 0 && col - k < n && board[row + k][col - k] == 'Q') return false;
            if(row - k >= 0 && row - k < n && col + k >= 0 && col + k < n && board[row - k][col + k] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> answer;
    //vector<string> current_combination
    void solve(int row, vector<string>& current_combination){
        int n = current_combination.size();
        if(row == n){
            answer.push_back(current_combination);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(row, col, current_combination)){
                current_combination[row][col] = 'Q';
                solve(row + 1, current_combination);
                current_combination[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i = 0; i < n; i++) s.push_back('.');
        vector<string>current_combination;
        for(int i = 0; i < n; i++){
            current_combination.push_back(s);
        }
        solve(0, current_combination);
        return answer;
    }
};
