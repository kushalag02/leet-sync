class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<int> indeg(n, 0);

        vector<vector<int>> adj(n, vector<int>(0));

        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        // Topo Sort

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<unordered_set<int>> ances(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                indeg[it]--;
                ances[it].insert(node);
                for (int i : ances[node]) {
                    ances[it].insert(i);
                }
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int itr : ances[i]) {
                ans[i].push_back(itr);
            }
        }

        for (int i = 0; i < n; i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};