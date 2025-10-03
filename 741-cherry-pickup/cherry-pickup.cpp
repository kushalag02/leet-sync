class Solution {
public:
    // 3 variables to monitor
    // no need of 4D DP as we can calculate the 4th variable by the sum as it is
    // constant

    // Instead of calculating for returning, just calculate for two persons starting at same time

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(0, 0, 0, grid, dp, n));
    }

    int solve(int r1, int c1, int c2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp, int n) {
        int r2 = r1 + c1 - c2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            return INT_MIN;
        }
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        if (dp[r1][c1][c2] != -1) {
            return dp[r1][c1][c2];
        }

        int val = 0;
        val += grid[r1][c1];
        if (c1 != c2) {
            val += grid[r2][c2];
        }
        int temp = max({solve(r1 + 1, c1, c2 + 1, grid, dp, n),
                        solve(r1 + 1, c1, c2, grid, dp, n),
                        solve(r1, c1 + 1, c2, grid, dp, n),
                        solve(r1, c1 + 1, c2 + 1, grid, dp, n)});

        val += temp;
        return dp[r1][c1][c2] = val;
    }
};
