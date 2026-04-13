class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2 == 1) return false;
        vector<int> dp(sum, 0);
        dp[0] = 1;

        for(int num : nums) {
            for(int i = sum/2 ; i >= num ; i--) {
                if(dp[i - num]) {
                    dp[i] = 1;
                }
            }
        }

        return dp[sum / 2];
    }
};
