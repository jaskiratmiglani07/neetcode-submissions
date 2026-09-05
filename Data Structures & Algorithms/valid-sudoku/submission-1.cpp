class Solution {
public:
    bool checkSubBox(int i, int j, vector<vector<char>>& board){
        unordered_map<int, int>freq;
        for(int r = i; r < i + 3; r++){
            for(int c = j; c < j + 3; c++){
                if(board[r][c] != '.' && freq.find(board[r][c]) != freq.end()) return false;
                if(board[r][c] != '.') freq[board[r][c]]++;                
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){//checking all the rows
            unordered_map<int, int>freq;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && freq.find(board[i][j]) != freq.end()) return false;
                if(board[i][j] != '.') freq[board[i][j]]++;
            }
        }  
        //checking all the columns  
        for(int j = 0; j < 9; j++){
            unordered_map<int, int>freq;
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.' && freq.find(board[i][j]) != freq.end()) return false;
                if(board[i][j] != '.') freq[board[i][j]]++;
            }
        }
        //checking the sub-boxes
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!checkSubBox(i, j, board)) return false;
            }
        }
        return true;
    }
};
