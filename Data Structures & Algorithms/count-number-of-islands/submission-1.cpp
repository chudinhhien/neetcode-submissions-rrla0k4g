class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};

    int dy[4] = {0, 0, -1, 1};

    int cnt = 0;

    void Try(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                Try(grid, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0 ; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ++cnt;
                    Try(grid, i, j);
                }
            }
        }

        return cnt;
    }
};
