class Solution {
public:
    vector<vector<int>> rs;
    unordered_map<int, bool> mp;

    void Try(int k, vector<int>& nums, vector<int>& current) {
        if(k == nums.size()) {
            rs.push_back(current);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++) {
            if(!mp[nums[i]]) {
                current.push_back(nums[i]);
                mp[nums[i]] = true;

                Try(k + 1, nums, current);

                current.pop_back();
                mp[nums[i]] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]] = false;
        }
        vector<int> current;
        Try(0, nums, current);

        return rs;
    }
};
