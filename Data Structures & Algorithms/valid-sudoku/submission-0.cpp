#include <cstring>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int dRow[10] = {0}, dCol[10][10] = {0}, dBox[10][10] = {0};
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                if(isdigit(board[i][j])) {
                    int num = board[i][j] - '0'; 
                    int rB = i / 3 , cB = j / 3;
                    if(dRow[num] == 1 || dCol[j][num] == 1 || dBox[3 * rB + cB][num] == 1) {
                        return false;
                    }
                    dRow[num] = 1;
                    dCol[j][num] = 1;
                    dBox[3 * rB + cB][num] = 1;
                }
            }
            memset(dRow, 0, sizeof(dRow));
        }
        return true;
    }
};


