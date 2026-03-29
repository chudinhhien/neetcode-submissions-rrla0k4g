class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for(const char& c:s) {
            cnt[c - 'a']++;
        }

        for(const char& c:t) {
            cnt[c - 'a']--;
        }

        for(const int& x:cnt) {
            if(x != 0) return false;
        }
        
        return true;
    }
};