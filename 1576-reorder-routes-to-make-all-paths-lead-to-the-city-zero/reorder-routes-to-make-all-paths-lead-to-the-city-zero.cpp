class Solution {
public:
    int minReorder(int n, vector<vector<int>>& A) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n, 0);
        int changes = 0;

        for (auto& c : A) {
            int u = c[0];
            int v = c[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& no : adj[node]) {
                int nei = no.first;
                int rev = no.second;
                if (!vis[nei]) {
                    vis[nei] = 1;
                    changes += rev;
                    q.push(nei);
                }
            }
        }
        return changes;
    }
};
