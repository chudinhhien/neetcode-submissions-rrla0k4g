class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int tmp = l + (r - l) / 2;
            if(nums[tmp] == target) return tmp;
            else if(target < nums[tmp]) r = tmp - 1;
            else l = tmp + 1;
        }
        return -1;
    }
};
