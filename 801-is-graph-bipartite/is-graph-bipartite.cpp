class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for (int j = 0; j < n; j++) { // Agar graph disconnected hua toh
            if (col[j] == -1) {
                queue<pair<int, int>> q;
                q.push({j, 0});
                col[j] = 0;

                while (!q.empty()) {
                    int node = q.front().first;
                    int color = q.front().second;
                    q.pop();

                    for (auto i : graph[node]) {
                        if (col[i] == -1) {
                            if (color == 0) {
                                col[i] = 1;
                            } else {
                                col[i] = 0;
                            }
                            q.push({i, col[i]});
                        }

                        else if (col[i] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
