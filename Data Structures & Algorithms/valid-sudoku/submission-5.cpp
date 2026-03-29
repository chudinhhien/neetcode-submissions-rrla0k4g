class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++){
            set<char> horizontal;
            set<char> vert;
            set<char> square;
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.'){
                if(horizontal.find(board[i][j])!=horizontal.end()){
                    return false;
                }
                else{
                    horizontal.insert(board[i][j]);
                }
                }
                if(board[j][i]!='.'){
                if(vert.find(board[j][i])!=vert.end()){
                    return false;
                }
                else{
                    vert.insert(board[j][i]);
                }
                }
                int row=(i/3)*3+j/3;
                int col=(i%3)*3 + j%3;
                if(board[row][col]!='.'){
                if(square.find(board[row][col])!=square.end()){
                    return false;
                }
                else{
                    square.insert(board[row][col]);
                }
                }
            }
        }
        return true;
    }
};
