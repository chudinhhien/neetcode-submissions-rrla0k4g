class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Thay vì mảng 2 chiều, ta dùng mảng 1 chiều các số nguyên
        // Mỗi bit của số nguyên sẽ đại diện cho một số trong Sudoku
        int rows[9] = {0}; // Lưu trạng thái 9 hàng
        int cols[9] = {0}; // Lưu trạng thái 9 cột
        int boxes[9] = {0}; // Lưu trạng thái 9 ô vuông

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') continue;

                int val = board[r][c] - '0'; // Lấy giá trị số (1-9)
                int pos = (1 << val); // Tạo mask: Đẩy bit 1 sang trái 'val' lần
                
                // Công thức tính index của hộp 3x3
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Kiểm tra xem bit tại vị trí 'val' đã bật chưa
                // Dùng phép AND (&)
                if((rows[r] & pos) > 0 || (cols[c] & pos) > 0 || (boxes[boxIndex] & pos) > 0) {
                    return false;
                }

                // Bật bit tại vị trí 'val' lên
                // Dùng phép OR (|=)
                rows[r] |= pos;
                cols[c] |= pos;
                boxes[boxIndex] |= pos;
            }
        }
        return true;
    }
};