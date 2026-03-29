class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        for(int i = 0 ; i < 26 ; i++) {
            if(freq[i] != 0) pq.push(freq[i]);
        }

        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;
            if(!pq.empty()) {
                int tmp = pq.top() - 1;
                pq.pop();

                if(tmp > 0) {
                    q.push({tmp, time +n});
                }
            }else{
                time = q.front().second;
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop(); 
            }
        }

        return time;
    }
};