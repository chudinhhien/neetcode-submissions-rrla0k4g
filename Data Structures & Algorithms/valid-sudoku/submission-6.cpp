#include <array>
#include <bitset>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bitset<9>, 9> rows, cols, squares;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int value = board[r][c] - '1';

                if (rows[r].test(value) || cols[c].test(value) || squares[(r / 3) * 3 + (c / 3)].test(value))
                    return false;

                rows[r].set(value);
                cols[c].set(value);
                squares[(r / 3) * 3 + (c / 3)].set(value);
            }
        }

        return true;
    }
};
