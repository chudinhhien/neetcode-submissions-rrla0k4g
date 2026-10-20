class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i, a in enumerate(nums):
            if (i > 0 and nums[i] == nums[i - 1]):
                continue

            j = i + 1
            k = len(nums) - 1

            while j < k:
                tmp = a + nums[j] + nums[k]

                if tmp > 0:
                    k -= 1
                elif tmp < 0:
                    j += 1
                else:
                    res.append([a, nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    k -= 1  
        return res