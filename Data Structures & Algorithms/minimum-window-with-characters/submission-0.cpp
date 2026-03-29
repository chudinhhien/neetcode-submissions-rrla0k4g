class Solution {
public:
    string minWindow(string s, string t) {
        // 1. Dùng mảng thay vì unordered_map sẽ nhanh hơn gấp nhiều lần (ASCII 128)
        int d[128] = {0};
        for (char c : t) d[c]++;

        int l = 0, have = 0;
        int need_count = 0;
        // Đếm xem có bao nhiêu ký tự duy nhất trong t
        for (int i = 0; i < 128; i++) if (d[i] > 0) need_count++;

        int minLen = INT_MAX;
        int startNode = 0; // Lưu vị trí bắt đầu của cửa sổ tốt nhất

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            
            // NẠP VÀO: Giảm nợ
            d[c]--;
            if (d[c] == 0) have++; // Vừa đủ nợ cho loại ký tự này

            // KHI ĐÃ ĐỦ ĐỒ: Vắt kiệt cửa sổ
            while (have == need_count) {
                // Cập nhật kết quả nếu tìm thấy đoạn ngắn hơn
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startNode = l;
                }

                // VỨT RA: Trả nợ
                char leftChar = s[l];
                if (d[leftChar] == 0) {
                    // Nếu đang vừa đủ mà vứt đi 1 cái -> Thiếu nợ ngay
                    have--;
                }
                d[leftChar]++;
                l++;
            }
        }

        // Nếu minLen vẫn là vô cực -> Không tìm thấy đoạn nào
        return minLen == INT_MAX ? "" : s.substr(startNode, minLen);
    }
};