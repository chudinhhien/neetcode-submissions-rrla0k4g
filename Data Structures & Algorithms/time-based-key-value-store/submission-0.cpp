class TimeMap {
public:
    // Tầng 1: Tìm Key (string), Tầng 2: Tìm Lịch sử (vector)
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Nếu key chưa từng tồn tại
        if (mp.find(key) == mp.end()) return "";
        
        // Dùng tham chiếu & để không phải copy mảng, tăng tốc độ cực lớn
        auto& history = mp[key];
        
        // Nếu timestamp hỏi còn nhỏ hơn cả thời điểm đầu tiên trong lịch sử
        if (timestamp < history[0].first) return "";

        int l = 0;
        int r = history.size() - 1;
        string ans = "";

        // Binary Search tìm phần tử lớn nhất mà <= timestamp
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (history[mid].first <= timestamp) {
                ans = history[mid].second; // Tạm lưu kết quả
                l = mid + 1;               // Thử tìm xem có cái nào gần hơn nữa không
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};