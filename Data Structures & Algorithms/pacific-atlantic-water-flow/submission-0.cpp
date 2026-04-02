class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int m, n; // Đưa m, n lên làm biến class để dùng chung cho tiện

    // Hàm BFS Đa Năng: Nhận vào grid, ma trận đánh dấu, và hàng đợi khởi điểm
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        while(!q.empty()) {
            auto [x, y] = q.front(); // C++17 structured binding cho gọn
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n 
                   && heights[nx][ny] >= heights[x][y] 
                   && !visited[nx][ny]) {
                    
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        queue<pair<int, int>> pacQ;
        queue<pair<int, int>> atlQ;

        // 1. Quét Cột trái (Pacific) và Cột phải (Atlantic)
        for(int i = 0; i < m; i++) {
            pacQ.push({i, 0}); pacific[i][0] = true;
            atlQ.push({i, n - 1}); atlantic[i][n - 1] = true;
        }

        // 2. Quét Hàng trên (Pacific) và Hàng dưới (Atlantic)
        for(int j = 0; j < n; j++) {
            pacQ.push({0, j}); pacific[0][j] = true;
            atlQ.push({m - 1, j}); atlantic[m - 1][j] = true;
        }

        // 3. Phóng 2 cơn sóng dâng ngược lên núi bằng 1 hàm duy nhất
        bfs(heights, pacific, pacQ);
        bfs(heights, atlantic, atlQ);

        // 4. Trạm kiểm duyệt: Chốt danh sách các ô thỏa mãn cả 2 điều kiện
        vector<vector<int>> rs;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    rs.push_back({i, j}); // Nhét tọa độ vào kết quả
                }
            }
        }

        return rs;
    }
};