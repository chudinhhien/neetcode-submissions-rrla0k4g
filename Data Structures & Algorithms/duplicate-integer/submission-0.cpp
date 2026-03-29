class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto& x : nums) {
            if(mp[x] == 1) return true;
            else mp[x]++;
        }
        return false;
    }
};