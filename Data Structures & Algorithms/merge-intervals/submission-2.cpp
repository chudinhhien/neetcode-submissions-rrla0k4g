class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Bắt luôn viền mảng rỗng cho an toàn
        if (intervals.empty()) return {}; 

        // 1. Sort luôn là chân ái
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        // 2. Chỉ 1 vòng lặp duy nhất
        for (const auto& interval : intervals) {
            // Nếu res trống HOẶC anh hiện tại hoàn toàn tách biệt với anh cuối cùng
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval); // Nhét thẳng vào
            } 
            // Nếu bị trùng
            else {
                res.back()[1] = max(res.back()[1], interval[1]); // Kéo dài cái đuôi ra
            }
        }

        return res;
    }
};