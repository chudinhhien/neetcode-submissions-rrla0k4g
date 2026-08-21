class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # mảng đếm -> max heap k 
        cnt = {}
        for num in nums:
            cnt[num] = cnt.get(num, 0) + 1
        return heapq.nlargest(k, cnt, key=lambda x: cnt[x])
