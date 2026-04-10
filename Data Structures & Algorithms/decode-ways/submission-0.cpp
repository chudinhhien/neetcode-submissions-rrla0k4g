class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> count(n + 1, 0);
        count[n] = 1;

        count[n - 1] = s[n - 1] != '0' ? 1 : 0;

        for(int i = n - 2 ; i >= 0 ; i--) {
            int tmp1 = 0, tmp2 = 0;
            if(s[i] != '0') {
                tmp1 = count[i + 1];
            }

            int tmp3 = (s[i] - '0') * 10 + s[i+1] - '0';
            if(tmp3 >= 10 && tmp3 <= 26) {
                tmp2 = count[i + 2];
            }

            count[i] = tmp1 + tmp2;
        }
        
        return count[0];
    }
};