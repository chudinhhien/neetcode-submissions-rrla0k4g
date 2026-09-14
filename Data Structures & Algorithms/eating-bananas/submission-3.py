class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        max_val = max(piles)
        left = 1
        right = max_val
        ans = max_val

        def numbersOfHours(rate: int) -> int:
            hours = 0

            for pile in piles:
                hours += math.ceil(pile / rate)
            
            return hours

        while(left <= right):
            mid = left + (right - left) // 2
            print(f"{mid}")

            tmp = numbersOfHours(mid)

            print(f"{tmp}")

            if(tmp <= h):
                ans = min(ans, mid)
                right = mid - 1
            else:
                left = mid + 1

        return ans