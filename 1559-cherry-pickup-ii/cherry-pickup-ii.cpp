class Solution {
public:
    // Logic mostly same as Cheery pickup - 1
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return max(0, solve(0, 0, m - 1, dp, grid, n, m));
    }

    int solve(int r, int c1, int c2, vector<vector<vector<int>>>& dp,
              vector<vector<int>>& grid, int n, int m) {
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) {
            return INT_MIN;
        }

        if (r == n - 1) {
            if (c1 == c2)
                return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int val = 0;
        val += grid[r][c1];
        if (c1 != c2) {
            val += grid[r][c2];
        }

        int maxi = INT_MIN;

        // Main effort here to calculate for each step - right, left, down

        maxi = max(maxi, solve(r + 1, c1 - 1, c2 - 1, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1 - 1, c2, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1 - 1, c2 + 1, dp, grid, n, m));

        maxi = max(maxi, solve(r + 1, c1, c2 - 1, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1, c2, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1, c2 + 1, dp, grid, n, m));

        maxi = max(maxi, solve(r + 1, c1 + 1, c2 - 1, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1 + 1, c2, dp, grid, n, m));
        maxi = max(maxi, solve(r + 1, c1 + 1, c2 + 1, dp, grid, n, m));

        val += maxi;
        return dp[r][c1][c2] = val;
    }
};
