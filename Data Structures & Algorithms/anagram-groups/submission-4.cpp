class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> cp = strs;
        vector<vector<string>> res;
        unordered_map<string, vector<string>> maps;
        int len = strs.size();
        for(int i=0;i<len;i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            maps[s].push_back(cp[i]);
        }
        for(auto x:maps) {
            res.push_back(x.second);
        }
        return res;
    }
};
