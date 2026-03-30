// TRICK FAST I/O: Tăng tốc độ đọc test case của hệ thống LeetCode lên gấp 10 lần
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int m, n; // Cache kích thước mảng để CPU chạy nhanh hơn

    int areaOfIsLand(vector<vector<int>>& grid, int x, int y) {
        int area = 1;
        grid[x][y] = 0; // Nhấn chìm ô hiện tại

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Dùng m, n đã cache thay vì gọi grid.size() liên tục
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                area += areaOfIsLand(grid, nx, ny);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // ĐÃ SỬA: Đưa biến này vào trong để an toàn tuyệt đối với mọi Test case
        int maxIslandNumber = 0; 

        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == 1) {
                    maxIslandNumber = max(maxIslandNumber, areaOfIsLand(grid, i, j));
                }
            }
        }

        return maxIslandNumber;
    }
};