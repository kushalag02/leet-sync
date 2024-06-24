class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].emplace_back(v, w);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; // Min-Heap
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[node])
                continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (distance + edgeWt < dist[adjNode]) {
                    dist[adjNode] = distance + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};