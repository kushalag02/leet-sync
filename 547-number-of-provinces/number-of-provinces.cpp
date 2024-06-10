class Solution {
public:
    void traversal(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto itr : adj[node]) {
            if (!vis[itr]) {
                traversal(itr, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                traversal(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};
