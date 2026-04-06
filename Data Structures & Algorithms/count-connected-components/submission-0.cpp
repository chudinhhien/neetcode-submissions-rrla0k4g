class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int x) {
        queue<int> q;
        q.push(x);
        visited[x] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int numConnected = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!visited[i]) {
                ++numConnected;
                bfs(adj, visited, i);
            }
        }

        return numConnected;
    }
};
