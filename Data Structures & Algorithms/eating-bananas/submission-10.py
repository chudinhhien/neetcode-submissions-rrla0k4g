class Solution:
    def eatingTimeWithK(self, piles: List[int], k: int) -> int:
        tmp = 0
        for pile in piles:
            tmp += (pile + k - 1) // k

        return tmp

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = r    

        while l <= r:
            k = l + (r - l) // 2
            eatingTime = self.eatingTimeWithK(piles, k)

            if eatingTime <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1

        return res   