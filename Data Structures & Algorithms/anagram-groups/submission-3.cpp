class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& s : strs) { // Lưu ý: không const để move sau này
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(std::move(s)); // Move string s gốc vào map luôn để tiết kiệm
        }

        vector<vector<string>> result;
        result.reserve(mp.size());
        for (auto& p : mp) {
            result.push_back(std::move(p.second));
        }
        return result;
    }
};