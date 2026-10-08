class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_pos = [-1] * 256
        res = 0
        l = 0

        for r, char in enumerate(s):
            idx = ord(char)

            if last_pos[idx] >= l:
                l = last_pos[idx] + 1

            last_pos[idx] = r
            res = max(res, r - l + 1)

        
        return res