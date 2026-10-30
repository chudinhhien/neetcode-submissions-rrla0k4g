class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # tư duy monotic stack + cướp ngôi
        stack = []
        res = 0
        heights.append(0)
        for i, height in enumerate(heights):
            j = i
            while stack and height < stack[-1][1]:
                j, h = stack.pop()
                res = max(res, (i - j) * h)
            stack.append((j, height))

        return res