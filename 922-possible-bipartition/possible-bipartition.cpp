class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& A) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < A.size(); i++) {
            int x = A[i][0];
            int y = A[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        return checkBipartite(adj, n);
    }

    bool checkBipartite(vector<vector<int>>& graph, int n) {
        vector<int> col(n + 1, -1);

        for (int j = 1; j <= n; j++) {
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
                        } else if (col[i] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
