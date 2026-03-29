class Solution {
public:
    vector<string> a = {"+", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> res;

    void Try(int k, string& digits, string& current) {
        if(k == digits.size()) {
            res.push_back(current);
            return;
        }

        string tmp = a[digits[k] - '0'];

        for(int i = 0 ; i < tmp.size(); i++) {
            current += tmp[i];
            Try(k + 1, digits, current);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res; 
        }

        string current = "";
        Try(0, digits, current);

        return res;
    }
};