class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned_s = "".join(c.lower() for c in s if c.isalnum())

        i = 0
        j = len(cleaned_s) - 1

        while(i < j):
            if(cleaned_s[i] != cleaned_s[j]):
                return False
            
            i += 1
            j -= 1
        
        return True