class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total = 1
        zeroes = []

        for num in range(len(nums)):
            if nums[num] == 0:
                zeroes.append(num)
            else:
                total *= nums[num]

        if len(zeroes) > 1:
            return [0] * len(nums)
        if len(zeroes) == 1:
            products = [0] * len(nums)
            products[zeroes[0]] = total
            return products

        products = []
        for num in nums:
            products.append(total // num)
        return products
