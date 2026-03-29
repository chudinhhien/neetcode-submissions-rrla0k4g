class Solution {
    vector<vector<int>> rs;

    bool d[51] = {false};

    void Try(int index, vector<int>& nums, vector<int>& currentSubSet, int target, int sum) {
        if(sum == target) {
            rs.push_back(currentSubSet);
            return;
        }

        if(index == nums.size()) {
            return;
        }

        for(int j = 0 ; j <= 1 ; j++) {
            if(j == 1) {
                currentSubSet.push_back(nums[index]);
                sum += nums[index];

                if(sum <= target) Try(index + 1, nums, currentSubSet, target, sum);

                currentSubSet.pop_back();
                sum -= nums[index];
            } else {
                int next_idx = index + 1;

                while(next_idx < nums.size() && nums[next_idx] == nums[index]) {
                    next_idx++;
                }

                Try(next_idx, nums, currentSubSet, target, sum);
            }

        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currentSubSet;

        sort(candidates.begin(), candidates.end());

        Try(0, candidates, currentSubSet, target, 0);

        return rs;
    }
};
