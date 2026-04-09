class Solution {
private:
    int expandArroundCenter(string& s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    } 
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;

        int start = 0;
        int maxLen = 0;

        for(int i = 0 ; i < s.length() ; i++) {
            //odd
            int len1 = expandArroundCenter(s, i, i);

            //even
            int len2 = expandArroundCenter(s, i, i + 1);

            int currentMaxLen = max(len1, len2);

            if(maxLen < currentMaxLen) {
                maxLen = currentMaxLen;

                start = i - (maxLen - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};