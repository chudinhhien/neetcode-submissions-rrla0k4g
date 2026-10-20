class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        count = {}

        for i in range(len(nums) - 1):
            j = i + 1
            k = len(nums) - 1

            if nums[i] > 0:
                continue

            if i > 0 and nums[i] == nums[i - 1]:
                continue

            while j < k:
                tmp = nums[i] + nums[j] + nums[k]
                if tmp == 0:
                    if tuple([nums[i], nums[j], nums[k]]) not in count:
                        res.append([nums[i], nums[j], nums[k]])
                        count[tuple([nums[i], nums[j], nums[k]])] = 1
                    j += 1
                    k -= 1
                elif tmp > 0:
                    k -= 1
                else:
                    j += 1
        
        return res