class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l < r) {
            if(nums[l] > nums[r]){
               if(nums[r] < nums[r - 1]) return nums[r];
               ++l;
               --r; 
            }else{
                --r;
            }
        }
        return nums[l];
    }
};
