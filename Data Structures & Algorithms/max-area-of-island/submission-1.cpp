class Solution {
public:
    int maxIslandNumber = 0;

    int dx[4] = {-1, 1, 0, 0};

    int dy[4] = {0, 0, -1, 1};

    int areaOfIsLand(vector<vector<int>>& grid, int x, int y) {
        int area = 1;

        grid[x][y] = 0;

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
                area += areaOfIsLand(grid, nx, ny);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0 ; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    maxIslandNumber = max(maxIslandNumber, areaOfIsLand(grid, i, j));
                }
            }
        }

        return maxIslandNumber;
    }
};
