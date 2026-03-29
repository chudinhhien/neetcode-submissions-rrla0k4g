class Solution {
    vector<vector<int>> rs;
public:
    void Try(int index, vector<int>& nums, vector<int>& currentNums) {
        if(index == nums.size()) {
            rs.push_back(currentNums);
            return;
        }

        for(int j = 0 ; j <= 1 ; j++) {
            if(j == 1) {
                currentNums.push_back(nums[index]);
            }

            Try(index + 1, nums, currentNums);

            if(j == 1) {
                currentNums.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currentSubSets;

        Try(0, nums, currentSubSets);

        return rs;
    }
};
