class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = {}
        f = {}
        for letter in s:
            d[letter] = d.get(letter,0) + 1
        for letter in t:
            f[letter] = f.get(letter,0) + 1

        return d == f