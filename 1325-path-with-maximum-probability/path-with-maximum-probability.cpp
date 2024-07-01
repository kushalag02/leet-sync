class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int src = start_node;
        int sink = end_node;
        priority_queue<pair<double, int>> pq; // Max - heap
        pq.push({1.0, src});

        vector<double> prob(n, 0.0);
        prob[src] = 1.0;

        while (!pq.empty()) {
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == sink) {
                return p;
            }

            if (p < prob[node]) {
                continue;
            }

            for (auto it : adj[node]) {
                int next = it.first;
                double pr = it.second;

                if (p * pr > prob[next]) {
                    prob[next] = p * pr;
                    pq.push({prob[next], next});
                }
            }
        }

        return 0.0;
    }
};
