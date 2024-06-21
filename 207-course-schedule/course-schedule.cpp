class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& A) {
        vector<vector<int>> adj(numCourses);
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int x = A[i][0];
            int y = A[i][1];
            adj[y].push_back(x);
        }
        vector<int> sorted = topoSort(numCourses, adj);
        if (sorted.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indeg(V, 0);
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            for (auto itr : adj[i]) {
                indeg[itr]++;
            }
        }
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto itr : adj[node]) {
                indeg[itr]--;
                if (indeg[itr] == 0) {
                    q.push(itr);
                }
            }
        }
        return ans;
    }
};
