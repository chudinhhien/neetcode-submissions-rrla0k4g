class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> sortedQueries;
        vector<int> output(m);

        sort(intervals.begin(), intervals.end());

        for(int i = 0 ; i < m ; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        int i = 0;

        for(auto sortedQuery : sortedQueries) {
            auto [query, index] = sortedQuery;
            int i = 0;

            while(i < n && intervals[i][0] <= query) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }

            while(!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            output[index] = pq.empty() ? -1 : pq.top().first;
        }

        return output;
    }
};
