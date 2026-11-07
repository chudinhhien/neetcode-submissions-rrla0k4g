class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while l < r:
            mid = l + (r - l) // 2
            print(f"{nums[l]}-{nums[mid]}-{nums[r]}")
            if nums[mid] <= nums[r]:
                r = mid
            else:
                l = mid + 1
        
        return nums[l]