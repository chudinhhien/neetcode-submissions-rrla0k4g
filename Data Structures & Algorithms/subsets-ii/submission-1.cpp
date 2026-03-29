class Solution {
public:
    vector<vector<int>> rs;

    void Try(int k, vector<int>& nums, vector<int>& current) {
        if(k == nums.size()) {
            rs.push_back(current);
            return;
        }

        for(int i = 0 ; i <= 1 ; i++) {
            if(i == 1) {
                current.push_back(nums[k]);

                Try(k + 1, nums, current);

                current.pop_back();
            }else {
                int cnt = k;
                while(cnt < nums.size() && nums[cnt] == nums[k]) {
                    ++cnt;
                }
                Try(cnt, nums, current);
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;

        Try(0, nums, current);

        return rs;
    }
};
