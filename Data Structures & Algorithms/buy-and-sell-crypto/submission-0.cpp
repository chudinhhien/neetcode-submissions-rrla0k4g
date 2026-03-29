class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minAtI[n];

        minAtI[0] = prices[0];
        int res = 0;

        for(int i = 1 ; i < n ; i++) {
            minAtI[i] = min(minAtI[i - 1], prices[i]);
            res = max(res, prices[i] - minAtI[i]);
        }

        return res;
    }
};
