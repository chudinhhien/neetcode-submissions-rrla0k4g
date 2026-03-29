class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: Key là chuỗi đã sort (VD: "aet"), Value là danh sách từ gốc (VD: "eat", "tea")
        unordered_map<string, vector<string>> map;
        
        for(string s : strs) {
            int cnt[26] = {0};
            for(char c : s) {
                cnt[c - 'a']++;
            }

            string key = "";
            for(int i = 0 ; i < 26; i++) {
                key += to_string(cnt[i]) + "#";
            }
            map[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};