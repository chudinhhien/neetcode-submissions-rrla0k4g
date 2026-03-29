class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int cnt[26] = {0};
        for(const char& c:s) {
            cnt[c - 'a']++;
        }

        for(const char& c:t) {
            int index = c - 'a';
            cnt[c - 'a']--;
            if(cnt[index] < 0 ) return false;
        }
        
        return true;
    }
};