class Solution {
public:
    vector<vector<int>> rs;

    void Try(vector<int>& nums, vector<int>& current, vector<bool>& visited) {
        if(current.size() == nums.size()) {
            rs.push_back(current);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++) {
            if(!visited[nums[i]]) {
                current.push_back(nums[i]);
                visited[nums[i]] = true;

                Try(nums, current, visited);

                current.pop_back();
                visited[nums[i]] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        rs.clear();
        vector<bool> visited(nums.size(), false);
        vector<int> current;
        Try(nums, current, visited);

        return rs;
    }
};