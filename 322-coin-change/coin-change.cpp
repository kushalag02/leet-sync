class Solution {
public:
    int solve(vector<int>& coins, int n, int m, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1e9;
        }
        if (m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (coins[n - 1] <= m) {
            dp[n][m] = min(solve(coins, n, m - coins[n - 1], dp) + 1,
                           solve(coins, n - 1, m, dp));
            return dp[n][m];
        } else {
            dp[n][m] = solve(coins, n - 1, m, dp);
            return dp[n][m];
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        if (solve(coins, n, amount, dp) == 1e9) {
            return -1;
        } else {
            return solve(coins, n, amount, dp);
        }
    }
};