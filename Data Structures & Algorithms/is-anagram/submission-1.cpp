class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int, int> mpS;
        unordered_map<int, int> mpT;
        for(const int& x:s) {
            mpS[x]++;
        }
        for(const int& x : t) {
            mpT[x]++;
        }
        for(const auto& [key, value] : mpS) {
            if(mpT[key] != value) return false;
        }

        return true;
    }
};