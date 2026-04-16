class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        res.push_back(intervals[i]);
        ++i;

        while(i < n) {
            vector<int>& tmp = res.back();

            if(intervals[i][0] <= tmp[1]) {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }else {
                res.push_back(intervals[i]);
            }

            ++i;
        }

        return res;
    }
};
