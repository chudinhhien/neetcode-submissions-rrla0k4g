class Solution {
public:
    vector<string> rs;

    void Try(int open, int close, int n, string& currentString) {
        if(currentString.size() == 2 * n) {
            rs.push_back(currentString);
            return;
        }

        if(open < n) {
            currentString += '(';

            Try(open + 1, close, n, currentString);

            currentString.pop_back();
        }

        if(close < open) {
            currentString += ')';

            Try(open, close + 1, n, currentString);

            currentString.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string currentString = "";
        Try(0, 0, n, currentString);

        return rs;
    }
};
