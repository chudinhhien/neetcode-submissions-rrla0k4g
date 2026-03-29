class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int res = 0;
        int n = heights.size();
        stack<int> st;

        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                res = max(res, height * width);
            }
            st.push(i);    
        }
        return res; 
    }
};
