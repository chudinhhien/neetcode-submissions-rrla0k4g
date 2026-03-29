class Solution {
    vector<vector<int>> rs;

    void Try(int index, vector<int>& nums, vector<int>& currentSubSet, int target, int sum) {
        if(sum == target) {
            rs.push_back(currentSubSet);
            return;
        }

        if(index == nums.size()) {
            return;
        }

        for(int j = 0 ; j <= 1 ; j++) {
            if(j == 0) {
                Try(index + 1, nums, currentSubSet, target, sum);
            }else {
                currentSubSet.push_back(nums[index]);
                sum += nums[index];

                if(sum <= target) Try(index, nums, currentSubSet, target, sum);

                currentSubSet.pop_back();
                sum -= nums[index];
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currentSubSet;
        Try(0, nums, currentSubSet, target, 0);

        return rs;
    }
};
