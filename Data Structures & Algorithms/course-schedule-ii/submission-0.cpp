class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto prerequisite : prerequisites) {
            ++inDegree[prerequisite[0]];
            adj[prerequisite[1]].push_back(prerequisite[0]);
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

        if(res.size() == numCourses) return res;
        else {
            res.clear();
            return res;
        }
    }
};
