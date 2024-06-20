class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto itr : graph[node]) {
            if (!vis[itr]) {
                if (dfs(itr, graph, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[itr] == 1) {
                return true;
            }
        }

        pathVis[node] = 0;
        vis[node] = 2; // Safe

        return false;
    }
};
