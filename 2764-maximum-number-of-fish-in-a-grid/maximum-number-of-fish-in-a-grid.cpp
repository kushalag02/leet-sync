class Solution {
public:
    int traversal(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int count = grid[r][c];

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    !vis[nRow][nCol] && grid[nRow][nCol] > 0) {
                    vis[nRow][nCol] = 1;
                    count += grid[nRow][nCol];
                    q.push({nRow, nCol});
                }
            }
        }
        return count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    int temp = traversal(grid, vis, i, j);
                    maxi = max(maxi, temp);
                }
            }
        }
        return maxi;
    }
};
