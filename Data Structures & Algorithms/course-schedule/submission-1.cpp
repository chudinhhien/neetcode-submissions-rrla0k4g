class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for(auto prerequisity : prerequisites) {
            inDegree[prerequisity[0]]++;

            adj[prerequisity[1]].push_back(prerequisity[0]);
        }

        queue<int> q;

        for(int i = 0 ; i < numCourses ; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        int count = 0;

        while(!q.empty()) {
            ++count;
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                --inDegree[v];
                if(inDegree[v] == 0) q.push(v);
            }
        }

        if(count == numCourses) return true;

        return false;
    }
};
