class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        setNums = set(nums)
        longest = 0

        for num in nums:
            if num - 1 not in setNums:
                length = 0
                while num + length in setNums:
                    length += 1
                
                longest = max(longest, length)
        
        return longest