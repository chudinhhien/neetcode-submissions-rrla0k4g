class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(const int& x : nums) {
            if(set.count(x)) return true;
            set.insert(x);
        }
        return false;
    }
};