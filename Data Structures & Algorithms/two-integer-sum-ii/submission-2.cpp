class Solution {
public:
    int binary_search(vector<int>& a, int x, int i, int j){
        while(i <= j) {
            int tmp = i + (j - i) / 2; // Cách viết này an toàn hơn tránh tràn số
            if(x == a[tmp]) return tmp;
            else if(x < a[tmp]) {
                j = tmp - 1; // Loại bỏ tmp
            } else {
                i = tmp + 1; // Loại bỏ tmp
            }
        }
        return -1; // Không tìm thấy
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0 ; i < n ; i++) {
            // Tìm số còn thiếu trong đoạn còn lại của mảng
            int complement = target - numbers[i];
            int res = binary_search(numbers, complement, i + 1, n - 1);
            
            if(res != -1) {
                return {i + 1, res + 1}; // Trả về 1-based index
            }
        }
        return {};
    }
};