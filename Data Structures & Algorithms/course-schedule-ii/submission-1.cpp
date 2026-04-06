class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(const auto& pre : prerequisites) {
            ++inDegree[pre[0]];
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;

        for(int i = 0 ; i < numCourses ; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            res.push_back(u);

            for(int v : adj[u]) {
                --inDegree[v];
                if(inDegree[v] == 0) q.push(v);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};