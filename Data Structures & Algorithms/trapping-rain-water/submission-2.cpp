class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int l = 0;
       int r = n - 1;
       int maxLeft = height[l];
       int maxRight = height[r];
       int res = 0;

       while(l < r) {
        if(maxLeft < maxRight) {
            res += maxLeft - height[l];
            l++;
            maxLeft = max(maxLeft, height[l]);
        }else {
            res += maxRight - height[r];
            r--;
            maxRight = max(maxRight, height[r]);
        }
       }
       return res;
    }
};
