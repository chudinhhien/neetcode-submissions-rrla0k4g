class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Dùng mảng 128 phần tử đại diện cho bảng mã ASCII
        // Gán tất cả bằng -1 (chưa từng xuất hiện)
        vector<int> dict(128, -1); 
        
        int l = 0;
        int res = 0;

        // Cho r chạy từ 0 đến cuối chuỗi
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            // Nếu ký tự c đã từng xuất hiện VÀ vị trí cũ của nó nằm BÊN TRONG cửa sổ hiện tại (>= l)
            if (dict[c] >= l) {
                // Kéo mép trái (l) vượt qua vị trí trùng lặp đó
                l = dict[c] + 1; 
            }

            // Cập nhật vị trí mới nhất của ký tự c
            dict[c] = r;

            // Lúc này cửa sổ [l, r] chắc chắn không có ký tự trùng, chốt độ dài
            res = max(res, r - l + 1);
        }

        return res;
    }
};