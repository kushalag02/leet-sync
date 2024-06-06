class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row,
              int column, int i, int j) {
        if (i == row - 1 && j == column - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == row - 1)
            return dp[i][j] =
                       grid[i][j] + solve(grid, dp, row, column, i, j + 1);
        if (j == column - 1)
            return dp[i][j] =
                       grid[i][j] + solve(grid, dp, row, column, i + 1, j);

        return dp[i][j] =
                   grid[i][j] + min(solve(grid, dp, row, column, i, j + 1),
                                    solve(grid, dp, row, column, i + 1, j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid.size();    // rows
        int m = grid[0].size(); // columns

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, dp, n, m, 0, 0);
    }
};
