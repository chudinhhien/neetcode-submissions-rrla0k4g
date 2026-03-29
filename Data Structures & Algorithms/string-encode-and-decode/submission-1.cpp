class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        // Tối ưu 1: Dùng tham chiếu (const string&) để tránh copy
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
            int j = i;
            
            // Tối ưu 2: Tự tính số nguyên thay vì dùng stoi(substr)
            // Cách này không tạo ra string tạm -> Nhanh hơn nhiều
            /*
             * Thay vì: int length = stoi(s.substr(i, j-i)); 
             * Ta tìm vị trí dấu #, sau đó dùng toán tử để parse số.
             * Tuy nhiên, trong C++ hiện đại, cách nhanh nhất để tìm dấu # là dùng find
             */
             
            // Tìm vị trí dấu #
            while (s[j] != '#') {
                j++;
            }
            
            // Parse độ dài trực tiếp từ chuỗi gốc, không cắt chuỗi con
            // &s[i] là con trỏ bắt đầu từ số, nó sẽ đọc đến khi gặp ký tự không phải số
            int length = 0;
            for (int k = i; k < j; k++) {
                length = length * 10 + (s[k] - '0');
            }

            // Tối ưu 3: Chỉ dùng substr 1 lần duy nhất để lấy nội dung
            // (Cái này bắt buộc phải copy để lưu vào vector)
            result.push_back(s.substr(j + 1, length));
            
            i = j + 1 + length;
        }
        return result;
    }
};