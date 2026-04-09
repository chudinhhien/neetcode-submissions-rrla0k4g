class Solution {
private:
    int countPalindromicString(string& s, int left, int right) {
        int cnt = 0;
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            ++cnt;
        }

        return cnt;
    }
public:
    int countSubstrings(string s) {
        if(s.length() <= 1) return s.length();

        int count = 0;

        for(int i = 0 ; i < s.length() ; i++) {
            count += countPalindromicString(s, i, i) + countPalindromicString(s, i, i + 1);
        }

        return count;
    }
};
