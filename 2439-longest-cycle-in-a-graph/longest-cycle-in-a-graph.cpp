class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                inDegree[edges[i]]++;
            }
        }
        // TopoSort (Kahn`s Algo.)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (edges[node] != -1) {
                inDegree[edges[node]]--;
                if (inDegree[edges[node]] == 0) {
                    q.push(edges[node]);
                }
            }
        }
        // inDegree = [0,0,1,3,1];

        int ans = -1;
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0 && visited[i] == -1) {
                int length = 0;
                int x = i;
                while (visited[x] == -1) {
                    visited[x] = i;
                    x = edges[x];
                    length++;
                }
                ans = max(ans, length);
            }
        }

        return ans;
    }
};
