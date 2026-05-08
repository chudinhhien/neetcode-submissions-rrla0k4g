class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res[n];

        res[0] = nums[0];

        int ans = res[0];

        for(int i = 1 ; i < n ; i++) {
            res[i] = max(res[i - 1] + nums[i], nums[i]);
            ans = max(ans, res[i]);
        }

        return ans;
    }
};
