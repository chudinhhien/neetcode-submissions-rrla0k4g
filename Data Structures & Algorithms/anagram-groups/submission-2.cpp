// Khai báo thư viện cần thiết
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>

using namespace std;

// Code tăng tốc I/O
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // 1. Định nghĩa cấu trúc Hasher cho array<int, 26>
    struct ArrayHasher {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;
            // Dùng thuật toán FNV-1a hoặc đơn giản là bitwise shift để tạo hash
            for (int x : a) {
                h = (h << 5) ^ (h >> 27) ^ x; // Một chút ma thuật bitwise
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 2. Map dùng array làm Key trực tiếp -> KHÔNG tốn chi phí tạo String
        unordered_map<array<int, 26>, vector<string>, ArrayHasher> mp;

        for (const auto& s : strs) { // Dùng const auto& để tránh copy string
            array<int, 26> count = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            // 3. Sử dụng move semantics (std::move) nếu có thể, 
            // nhưng ở đây ta push bản sao của s vào vector
            mp[count].push_back(s);
        }

        vector<vector<string>> result;
        // Reserve bộ nhớ trước để tránh vector phải resize nhiều lần
        result.reserve(mp.size());

        for (auto& p : mp) {
            // 4. Dùng std::move để "chuyển nhà" dữ liệu thay vì copy
            // Giúp chuyển vector con vào vector kết quả cực nhanh
            result.push_back(std::move(p.second));
        }

        return result;
    }
};