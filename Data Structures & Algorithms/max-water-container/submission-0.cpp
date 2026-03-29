class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = n - 1 ; j > i ; j--) {
                int tmp = min(heights[i], heights[j]) * (j - i);
                res = max(res, tmp);
            }
        }

        return res;
    }
};
