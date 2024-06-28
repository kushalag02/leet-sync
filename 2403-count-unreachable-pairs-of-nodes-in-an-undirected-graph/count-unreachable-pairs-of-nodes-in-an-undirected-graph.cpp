class Solution {
public:
    long long dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;
        long long count = 1;
        for (auto i : adj[node]) {
            if (!vis[i]) {
                count += dfs(adj, vis, i);
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans = 0;
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long connected = 0;
        vector<int> vis(n, 0);

        vector<long long> deg(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long comp = dfs(adj, vis, i);
                deg.push_back(comp);
            }
        }
        for (long long i : deg) {
            connected += (i * (i - 1) / 2);
        }
        ans = totalPairs - connected;
        return ans;
    }
};