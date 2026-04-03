class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';

        for(int i = 0 ; i < 4 ; i++) {
            int dr = r + dx[i];
            int dc = c + dy[i];

            dfs(board, dr, dc);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i < n ; i++) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for(int i = 0 ; i < m ; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
