class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int freshCount = 0;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    ++freshCount;
                }
            }
        }

        int minutes = 0;

        while(!q.empty() && freshCount > 0) {
            int qSize = q.size();

            for(int i = 0; i < qSize; i++) {
                auto it = q.front();
                q.pop();

                int x = it.first;
                int y = it.second;

                for(int d = 0 ; d < 4 ; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshCount--;
                        q.push({nx, ny});
                    }
                }
            }
            ++ minutes;
        }

        if (freshCount > 0) return -1;
        return minutes;
    }
};