class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        count = {}

        for idx, val in enumerate(nums):
            tmp = target - val

            if tmp in count:
                return [count[tmp], idx]
            else:
                count[val] = idx