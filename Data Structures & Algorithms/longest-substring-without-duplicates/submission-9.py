class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        start = 0
        max_ans = 0
        visited = [-1] * 256

        for end, char in enumerate(s):
            code = ord(char)

            if visited[code] >= start:
                start = visited[code] + 1
            
            visited[code] = end
            max_ans = max(max_ans, end - start + 1)
        
        return max_ans