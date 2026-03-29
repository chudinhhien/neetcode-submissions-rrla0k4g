class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(const auto& it : mp) {
            int num = it.first;
            int freq = it.second;

            minHeap.push({freq, num});

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> rs;

        while(!minHeap.empty()) {
            rs.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return rs;
    }
};
