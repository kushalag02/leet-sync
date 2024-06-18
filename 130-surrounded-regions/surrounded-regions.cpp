class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (vis[i][0] == 0 && grid[i][0] == 'O') {
                dfs(i, 0, grid, vis);
            }
            if (vis[i][m - 1] == 0 && grid[i][m - 1] == 'O') {
                dfs(i, m - 1, grid, vis);
            }
        }

        for (int j = 0; j < m; j++) {
            if (vis[0][j] == 0 && grid[0][j] == 'O') {
                dfs(0, j, grid, vis);
            }
            if (vis[n - 1][j] == 0 && grid[n - 1][j] == 'O') {
                dfs(n - 1, j, grid, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && vis[i][j] == 0) {
                    grid[i][j] = 'X';
                }
            }
        }
        // return grid;
    }
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 'O') {
                dfs(nrow, ncol, grid, vis);
                // vis[nrow][ncol] = 1;
            }
        }
    }
};