class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = l + (r - l) // 2
            print(f"{nums[l]}-{nums[mid]}-{nums[r]}")

            if nums[mid] == target:
                return mid
            elif nums[l] <= nums[mid]:
                # print(f"{nums[l]}---{nums[mid]} + {nums[mid + 1]}----{nums[r]}")
                if nums[l] <= target < nums[mid]:
                    # print(f"{target} thuoc {nums[l]}---{nums[mid]} + {nums[mid + 1]}----{nums[r]}")
                    r = mid - 1
                else:
                    # print(f"{nums[l]}---{nums[mid]} + {target} thuoc {nums[mid + 1]}----{nums[r]}")
                    l = mid + 1
            else:
                # print(f"{nums[l]}---{nums[mid]} + {nums[mid + 1]}----{nums[r]}")
                if nums[mid] < target <= nums[r]:
                    # print(f"{nums[l]}---{nums[mid]} + {target} thuoc {nums[mid + 1]}----{nums[r]}")
                    l = mid + 1
                else:
                    # print(f"{target} thuoc {nums[l]}---{nums[mid]} + {nums[mid + 1]}----{nums[r]}")
                    r = mid - 1
        
        return -1