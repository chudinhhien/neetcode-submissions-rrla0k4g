class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = nums[0]; //tích lớn nhất kết thúc tại i
        int minSoFar = nums[0]; //tích nhỏ nhất kết thúc tại i

        int globalMax = nums[0];

        for(int i = 1 ; i < n ; i++) {
            int tmpMax = max(nums[i], max(nums[i] * maxSoFar, nums[i] * minSoFar));
            minSoFar = min(nums[i], min(nums[i] * maxSoFar, nums[i] * minSoFar));
            maxSoFar = tmpMax;
            globalMax = max(globalMax, maxSoFar);
        }

        return globalMax;
    }
};
