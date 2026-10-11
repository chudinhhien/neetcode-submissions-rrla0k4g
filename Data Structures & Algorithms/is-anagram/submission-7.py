class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = [0] * 26

        for c in s:
            idx = ord(c) - ord('a')

            count[idx] += 1
        
        for c in t:
            idx = ord(c) - ord('a')

            count[idx] -= 1
        
        for val in count:
            if val != 0:
                return False

        return True