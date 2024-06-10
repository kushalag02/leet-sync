class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(m - 1, n - 1, dp);
    }

    int solve(int m, int n, vector<vector<int>>& dp) {
        if (n == 0 || m == 0)
            return 1;
        if (dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }
};
