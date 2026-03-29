class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            // Thay set bằng 3 số nguyên (Bitmask) -> Chỉ tốn 12 bytes
            int rowMask = 0;
            int colMask = 0;
            int boxMask = 0;
            
            for(int j = 0; j < 9; j++) {
                // Kiểm tra Hàng i
                if(board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    if((rowMask >> val) & 1) return false;
                    rowMask |= (1 << val);
                }
                
                // Kiểm tra Cột i (Đảo vị trí j, i)
                if(board[j][i] != '.') {
                    int val = board[j][i] - '0';
                    if((colMask >> val) & 1) return false;
                    colMask |= (1 << val);
                }
                
                // Kiểm tra Ô vuông i (Dùng công thức thần thánh)
                int r = (i / 3) * 3 + j / 3;
                int c = (i % 3) * 3 + j % 3;
                if(board[r][c] != '.') {
                    int val = board[r][c] - '0';
                    if((boxMask >> val) & 1) return false;
                    boxMask |= (1 << val);
                }
            }
        }
        return true;
    }
};