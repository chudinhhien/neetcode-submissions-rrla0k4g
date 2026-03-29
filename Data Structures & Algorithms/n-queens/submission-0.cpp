class Solution {
public:
    vector<vector<string>> res;
    vector<string> output(vector<int>& q, int& n) {
        vector<string> board;
        for(int i = 0 ; i < n ; i++) {
            string row = "";
            for(int j = 0 ; j < n ; j++) {
                if(j == q[i]) row += 'Q';
                else row += '.';
            }
            board.push_back(row);
        }

        return board;
    }

    bool check(vector<int>& q, int k, int i) {
        for(int j = 0 ; j < k ; j++) {
            if(q[j] == i) return false;

            if(abs(j - k) == abs(q[j] - i)) return false;
        }

        return true;
    }

    void Try(int k, int& n, vector<int>& q) {
        if(k == n) {
            res.push_back(output(q, n));
            return;
        }

        for(int i = 0 ; i < n ; i++) {
            if(check(q, k, i)) {
                q[k] = i;
                Try(k + 1, n, q);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> q(n, 0);

        Try(0, n, q);

        return res;
    }
};
