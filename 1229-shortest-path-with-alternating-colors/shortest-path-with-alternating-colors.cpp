class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        for (auto& e : redEdges) {
            red[e[0]].push_back(e[1]);
        }
        for (auto& e : blueEdges) {
            blue[e[0]].push_back(e[1]);
        }

        vector<int> ans(n, -1);
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        queue<pair<int, int>> q; // {node,color}

        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            int u = q.front().first;
            int color = q.front().second;
            q.pop();
            int d = dist[u][color];

            if (color == 0) {
                for (int v : blue[u]) {
                    if (dist[v][1] > d + 1) {
                        dist[v][1] = d + 1;
                        q.push({v, 1});
                    }
                }
            } else {
                for (int v : red[u]) {
                    if (dist[v][0] > d + 1) {
                        dist[v][0] = d + 1;
                        q.push({v, 0});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            if (best != INT_MAX)
                ans[i] = best;
        }
        return ans;
    }
};
