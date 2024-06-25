class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 1];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, bfs(i, adj, n));
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    int bfs(int start, vector<int> adj[], int n) {
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        dist[start] = 0;
        q.push({start, -1}); // {node,parent}
        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int itr : adj[node]) {
                if (dist[itr] == INT_MAX) {
                    dist[itr] = dist[node] + 1;
                    q.push({itr, node});
                } else if (itr != parent) {
                    ans = min(ans, dist[node] + dist[itr] + 1);
                }
            }
        }

        return ans;
    }
};