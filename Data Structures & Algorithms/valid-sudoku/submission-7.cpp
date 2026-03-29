class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) {
            set<char> row;
            set<char> col;
            set<char> square;
            for(int j = 0 ; j < 9 ; j++) {
                if(board[i][j]!='.'){
                    if(row.find(board[i][j])!=row.end()) {
                        return false;
                    }else
                        row.insert(board[i][j]);
                }
                
                if(board[j][i]!='.'){
                    if(col.find(board[j][i])!=col.end()) {
                        return false;
                    }else
                        col.insert(board[j][i]);
                }
                
                int r = 3 * (i / 3) + j / 3;
                int c = 3 * (i % 3) + j % 3;

                if(board[r][c]!='.') {
                    if(square.find(board[r][c])!=square.end()) {
                        return false;
                    }else
                        square.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
