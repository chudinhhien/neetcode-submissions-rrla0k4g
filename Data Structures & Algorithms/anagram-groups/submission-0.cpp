class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: Key là chuỗi đã sort (VD: "aet"), Value là danh sách từ gốc (VD: "eat", "tea")
        unordered_map<string, vector<string>> map;
        
        for(string s : strs) {
            string key = s; // 1. Tạo bản sao để sort
            sort(key.begin(), key.end()); // 2. Sort bản sao -> "aet"
            
            // 3. Nhét chuỗi gốc vào đúng nhóm của nó
            // C++ tự động tạo vector mới nếu key chưa tồn tại
            map[key].push_back(s); 
        }

        // 4. Chuyển từ Map sang Vector kết quả
        vector<vector<string>> result;
        for(auto& pair : map) {
            result.push_back(pair.second); // Chỉ lấy phần Value (Vector con)
        }
        
        return result;
    }
};