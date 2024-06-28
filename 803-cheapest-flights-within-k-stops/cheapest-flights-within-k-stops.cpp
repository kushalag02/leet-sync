class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q; // {stops, {node, dist}}
        q.push({0, {src, 0}});

        while (!q.empty()) {
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stop > k)
                continue;

            for (auto itr : adj[node]) {
                int next = itr.first;
                int paisa = itr.second;
                if (cost + paisa < dist[next] && stop <= k) {
                    dist[next] = cost + paisa;
                    q.push({stop + 1, {next, cost + paisa}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};
