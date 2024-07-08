class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      // Prims Algo
        int n = points.size();
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int w = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, w});
            }
        }

        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<bool> vis(n, false);
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node] == true) {
                continue;
            }
            vis[node] = true;
            ans += dist;

            for (auto neighbour : adj[node]) {
                int adjNode = neighbour.first;
                int distance = neighbour.second;

                if (!vis[adjNode]) {
                    pq.push({distance, adjNode});
                }
            }
        }
        return ans;
    }
};