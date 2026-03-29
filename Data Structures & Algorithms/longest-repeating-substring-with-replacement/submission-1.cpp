class Solution {
public:
    int characterReplacement(string s, int k) {
        int dict[256] = {0};
        int left = 0;
        int max_count = 0, res = 0;
        for(int right = 0 ; right < s.size() ; right++) {
            char c = s[right];
            dict[c]++;
            max_count = max(max_count, dict[c]);

            if((right - left + 1) - max_count > k) {
                dict[s[left]]--;
                ++left;
            }else{
                res = max(res, right - left + 1);
            }
        }

        return res;
    }
};
