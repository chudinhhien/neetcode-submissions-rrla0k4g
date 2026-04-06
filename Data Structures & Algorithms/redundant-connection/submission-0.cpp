class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int u, int v, int n) {
        vector<bool> visited(n + 1, false);

        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(int y : adj[x]) {
                if(y == v) return true;

                if(!visited[y]) {
                    q.push(y);
                    visited[y] = true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for(const auto& edge : edges) {
            int u = edge[0]; int v = edge[1];
            if(bfs(adj, u, v, n)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};