class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++; // Đếm tần suất

        // buckets[i] chứa danh sách các số xuất hiện đúng i lần
        vector<vector<int>> buckets(nums.size() + 1);

        for(auto &[number, count] : mp) {
            buckets[count].push_back(number);
        }

        vector<int> rs;
        // Duyệt ngược từ tần suất cao nhất về thấp nhất
        for(int i = nums.size(); i >= 0; i--) {
            // Nếu bucket này có chứa số
            if(buckets[i].size() > 0) {
                for(int x : buckets[i]) {
                    rs.push_back(x);
                    
                    //Kiểm tra đủ k chưa ngay sau khi thêm
                    if(rs.size() == k) return rs; 
                }
            }
        }

        return rs;
    }
};