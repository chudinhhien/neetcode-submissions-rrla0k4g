class Solution {
public:
    /*
        Tree được định  nghĩa như sau :
        1. phải có n - 1 cạnh
        2. ko tồn tại chu trình
    */

    bool isConnectivity(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        queue<int> q;
        
        for(const auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        q.push(0);
        visited[0] = true;
        int count = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ++count;

            for(int v : adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return count == n ? true : false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 != edges.size()) return false;

        return isConnectivity(n, edges);
    }
};