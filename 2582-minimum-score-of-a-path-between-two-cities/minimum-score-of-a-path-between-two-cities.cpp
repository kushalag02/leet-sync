class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;

        int mini = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto itr : adj[node]) {
                int vertex = itr.first;
                int weight = itr.second;

                mini = min(mini, weight);

                if (!visited[vertex]) {
                    visited[vertex] = 1;
                    q.push(vertex);
                }
            }
        }

        return mini;
    }
};