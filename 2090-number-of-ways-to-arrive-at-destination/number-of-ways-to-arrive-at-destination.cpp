class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int src = 0;
        int sink = n - 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0); // Main concept
        dist[src] = 0;
        ways[src] = 1;

        pq.push({0, src});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto node : adj[u]) {
                int v = node.first;
                int w = node.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[u] + w == dist[v]) { // Main step
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[sink];
    }
};
