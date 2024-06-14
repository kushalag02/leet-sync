class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;

        int area = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            area += dfs(grid, nrow, ncol);
        }

        return area;
    }
};
