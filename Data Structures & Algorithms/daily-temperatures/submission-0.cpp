class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> result(n);
        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) {
                st.push({i, temperatures[i]});
            }else {
                if(!st.empty()) {
                    
                }
                while(!st.empty() && temperatures[i] > st.top().second) {
                    result[st.top().first] = i - st.top().first;
                    st.pop();
                }
                st.push({i, temperatures[i]});
            }
        }

        return result;
    }
};
