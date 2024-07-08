class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot) {
            if (rank[aRoot] < rank[bRoot]) {
                parent[aRoot] = bRoot;
            } else if (rank[aRoot] > rank[bRoot]) {
                parent[bRoot] = aRoot;
            } else {
                parent[aRoot] = bRoot;
                rank[bRoot]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> edges; //{ weight, {p1, p2}}
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int weight = abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);
                edges.push_back({weight, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());

        int ans = 0;
        int numEdges = 0;
        for (auto it : edges) {
            int weight = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (find(u) != find(v)) {
                unionSets(u, v);
                ans += weight;
                numEdges++;
                if (numEdges == n - 1) {
                    break;
                }
            }
        }

        return ans;
    }
};
