class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        // Reserve trước bộ nhớ nếu có thể ước lượng, để tránh resize nhiều lần
        // Nhưng ở đây ta cứ cộng bình thường cũng ổn
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            // 1. Dùng s.find để tìm dấu # (Tối ưu phần cứng tốt hơn while loop)
            size_t j = s.find('#', i);
            
            // 2. Tính độ dài bằng tay (Manual Parsing)
            // Thay vì cắt chuỗi (substr) rồi đổi sang số (stoi) -> Rất tốn time
            // Ta tính trực tiếp từ ký tự số.
            // Ví dụ: "12" -> 1*10 + 2 = 12
            int length = 0;
            for (int k = i; k < j; k++) {
                length = length * 10 + (s[k] - '0');
            }
            
            // 3. Chỉ substr đúng 1 lần duy nhất để lấy nội dung
            // Đây là thao tác bắt buộc
            result.push_back(s.substr(j + 1, length));
            
            // Nhảy cóc
            i = j + 1 + length;
        }
        return result;
    }
};