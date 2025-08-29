class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(grid, vis, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (grid[i][j] == 1 || vis[i][j])
            return true;

        vis[i][j] = 1;
        bool closed = true;

        vector<int> R = {-1, 0, 1, 0};
        vector<int> C = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = i + R[k];
            int ncol = j + C[k];

            closed &= dfs(grid, vis, nrow, ncol);
        }
        return closed;
    }
};