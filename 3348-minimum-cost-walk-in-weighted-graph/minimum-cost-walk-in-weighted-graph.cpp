class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> component;

    void dfs(int node, int compId, int& andValue) {
        component[node] = compId;
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            andValue &= weight;
            if (component[neighbor] == -1) {
                dfs(neighbor, compId, andValue);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        adj.resize(n);
        component.assign(n, -1);
        vector<int> minAndValue(n, INT_MAX);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // To calculate number of connected components in the forest
        // minAndValue[] stors the min AND of each connected comp

        int compId = 0;
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                int andValue = INT_MAX;
                dfs(i, compId, andValue);
                minAndValue[compId] = andValue;
                compId++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int s = q[0];
            int t = q[1];
            if (component[s] != component[t])
                ans.push_back(-1);
            else
                ans.push_back(minAndValue[component[s]]);
        }

        return ans;
    }
};