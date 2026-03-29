class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;

            // Kiểm tra nửa bên trái có được sắp xếp chuẩn không
            if (nums[l] <= nums[mid]) {
                // Nếu target nằm trong vùng sắp xếp chuẩn của nửa trái
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
            // Ngược lại, nửa bên phải phải là nửa chuẩn
            else {
                // Nếu target nằm trong vùng sắp xếp chuẩn của nửa phải
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};