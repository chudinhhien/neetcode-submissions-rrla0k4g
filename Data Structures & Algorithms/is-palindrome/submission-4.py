class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ""
        s = s.lower()
        for i in s:
            if i.isalnum() and not i.isspace():
                st+=i
            
        return st == st[::-1]