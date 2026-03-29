auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;

        // 1. Sort mảng gốc để các số giống nhau đứng cạnh nhau
        // Tận dụng CPU Cache cực tốt -> Nhanh hơn Hashing
        sort(nums.begin(), nums.end());

        // 2. Đếm tần suất và lưu vào vector pair
        vector<pair<int, int>> counts; // {tần suất, giá trị}
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            int count = 1;
            // Đếm các số giống nhau liên tiếp
            while (i + 1 < n && nums[i] == nums[i+1]) {
                count++;
                i++;
            }
            counts.push_back({count, nums[i]});
            i++;
        }

        // 3. Dùng Partial Sort (chỉ sort lấy top K phần tử)
        // nth_element nhanh hơn sort toàn bộ -> O(N) trung bình
        nth_element(counts.begin(), counts.begin() + k, counts.end(), greater<pair<int, int>>());
        
        // 4. Lấy kết quả
        vector<int> res;
        for (int j = 0; j < k; ++j) {
            res.push_back(counts[j].second);
        }
        
        return res;
    }
};