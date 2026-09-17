class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(len(prices)):
            j = i + 1
            print(j)

            while j < len(prices) and (prices[j] - prices[i]) >= 0:
                ans = max(ans, prices[j] - prices[i])
                j += 1
    
        return ans