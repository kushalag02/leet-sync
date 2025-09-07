class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int origColor = grid[row][col];

        dfs(grid, ans, vis, row, col, origColor, color);

        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& ans,
             vector<vector<int>>& vis, int row, int col, int origColor,
             int newColor) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        bool flag = false;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) {
                flag = true;
            } else if (grid[nrow][ncol] != origColor) {
                flag = true;
            } else if (!vis[nrow][ncol]) {
                dfs(grid, ans, vis, nrow, ncol, origColor, newColor);
            }
        }

        if (flag) {
            ans[row][col] = newColor;
        }
    }
};
