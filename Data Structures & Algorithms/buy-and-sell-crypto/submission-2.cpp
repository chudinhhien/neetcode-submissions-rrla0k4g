class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0]; // Chỉ cần 1 biến để nhớ giá rẻ nhất
        int res = 0;

        for(int i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]); // Cập nhật giá rẻ nhất
            res = max(res, prices[i] - min_price); // Chốt lời thử
        }

        return res;
    }
};