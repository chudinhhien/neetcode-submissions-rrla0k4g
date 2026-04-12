class Solution {
private:
    bool tryBreak(string& s, int start, unordered_set<string>& dict, vector<int>& memo) {
        if(start == s.size()) return true;

        if(memo[start] == -1) {
            for(int end = start ; end < s.size() ; end++) {
                string word = s.substr(start, end - start + 1);

                if(dict.count(word)) {
                    if(tryBreak(s, end + 1, dict, memo)) return true;
                }
            }
        }else {
            return memo[start];
        }

        memo[start] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);

        unordered_set<string> dict;

        for(string word : wordDict) dict.insert(word);

        return tryBreak(s, 0, dict, memo);
    }
};