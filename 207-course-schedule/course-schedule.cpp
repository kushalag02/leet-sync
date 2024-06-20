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

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& recStack, bool& hasCycle, stack<int>& st) {
        if (hasCycle)
            return;

        vis[node] = 1;
        recStack[node] = 1;

        for (auto itr : adj[node]) {
            if (!vis[itr]) {
                dfs(itr, adj, vis, recStack, hasCycle, st);
            } else if (recStack[itr]) {
                hasCycle = true;
                return;
            }
        }

        recStack[node] = 0;
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> vis(V, 0);
        vector<int> recStack(V, 0);
        vector<int> ans;
        bool hasCycle = false;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, recStack, hasCycle, st);
                if (hasCycle) {
                    return {};
                }
            }
        }

        while (!st.empty()) {
            int val = st.top();
            st.pop();
            ans.push_back(val);
        }

        return ans;
    }
};
