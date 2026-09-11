class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        left_max = height[left]
        right = len(height) - 1
        right_max = height[len(height) - 1]
        ans = 0

        while(left < right):
            if(left_max < right_max):
                ans += left_max - height[left]
                left_max = max(left_max, height[left + 1])
                left += 1
            else:
                ans += right_max - height[right]
                right_max = max(right_max, height[right - 1])
                right -= 1
        return ans