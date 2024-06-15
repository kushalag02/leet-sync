class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
            queue<pair<pair<int, int>, int>>& q, int n, int m) {
        int maxi = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int nodeRow = q.front().first.first;
            int nodeCol = q.front().first.second;
            int time = q.front().second;
            maxi = max(maxi, time);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = nodeRow + delRow[i];
                int ncol = nodeCol + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxi;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        return bfs(grid, vis, q, n, m);
    }
};
