class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& A) {
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (int i = 0; i < A.size(); i++) {
            int x = A[i][0];
            int y = A[i][1];
            adj[y].push_back(x);
            adj[x].push_back(y);
            degree[x]++;
            degree[y]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                result.push_back(node);

                for (int itr : adj[node]) {
                    degree[itr]--;
                    if (degree[itr] == 1) {
                        q.push(itr);
                    }
                }
            }
        }

        return result;
    }
};