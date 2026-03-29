class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int d[128] = {0};

        for(char c : s1) {
            d[c]++;
        }

        int l = 0;
        
        for(int r = 0 ; r < s2.size() ; r++) {
            d[s2[r]]--;

            while(d[s2[r]] < 0) {
                d[s2[l]]++;
                l++;
            }

            if(r - l + 1 == s1.size()) return true;
        }

        return false;
    }
};

