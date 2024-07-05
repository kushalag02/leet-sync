class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, A, dp);
    }

    int solve(int n, int m, vector<vector<int>>& A, vector<vector<int>>& dp) {
        if (n < 0 || m < 0) {
            return 0;
        }
        if (A[n][m] == 1) {
            return dp[n][m] = 0;
        }
        if (n == 0 && m == 0) {
            return 1;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        return dp[n][m] = solve(n - 1, m, A, dp) + solve(n, m - 1, A, dp);
    }
};
