class Solution {
public:
    int dfs(int current, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxi = 0;
        for (int node : adj[current]) {
            maxi = max(maxi, dfs(node, adj, informTime));
        }
        return informTime[current] + maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                continue;
            }
            adj[manager[i]].push_back(i);
        }

        return dfs(headID, adj, informTime);
    }
};