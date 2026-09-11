class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while(left <= right):
            tmp = (left + right) // 2
            print(f"{left}-{tmp}-{right}")
            if nums[tmp] == target:
                return tmp
            elif target > nums[tmp]:
                left = tmp + 1
            else:
                right = tmp - 1
        
        return -1