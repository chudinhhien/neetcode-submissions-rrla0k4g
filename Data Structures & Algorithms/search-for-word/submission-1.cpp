class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool Try(string& word, int index, vector<vector<char>>& board, int x, int y) {
        if(board[x][y] != word[index]) {
            return false;
        }

        if(index == word.size() - 1) return true;

        char c = board[x][y];
        board[x][y] = '*';

        for(int i = 0  ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] != '*') {
                if(Try(word, index + 1, board, nx, ny) == true) {
                    return true;
                }
            }
        }

        board[x][y] = c;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++) {
            for(int j = 0 ; j < board[0].size() ; j++) {
                if(board[i][j] == word[0] && Try(word, 0, board, i, j) == true) return true;
            }
        }

        return false;
    }
};
