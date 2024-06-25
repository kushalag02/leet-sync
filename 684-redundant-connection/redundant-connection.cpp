class Solution {
public:
    bool detect(int src, vector<int> adj[], vector<int>& vis) {
        // detect the cycles in undirected graph
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto itr : adj[node]) {
                if (!vis[itr]) {
                    vis[itr] = 1;
                    q.push({itr, node});
                } else if (parent != itr) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n + 1];
        vector<int> vis(n + 1, 0);

        for (auto edge : edges) {
            for (int i = 0; i < vis.size(); i++) {
                vis[i] = 0;
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            if (detect(edge[0], adj, vis) == true) {
                return edge;
            }
        }

        return {};
    }
};
