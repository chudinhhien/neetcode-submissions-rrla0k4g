class Solution {
private:
    int robRange(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;

        for(int i = start ; i <= end ; i++) {
            int current = max(prev1, prev2 + nums[i]);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        int max1 = robRange(nums, 0, n - 2);

        int max2 = robRange(nums, 1, n - 1);

        return max(max1, max2);
    }
};