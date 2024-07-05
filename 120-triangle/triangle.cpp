class Solution {
public:
    int solve(vector<vector<int>>& A, vector<vector<int>>& dp, int i,
              int j) {
        if (i == A.size() - 1)
            return A[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(A, dp, i + 1, j);
        int diagonal = solve(A, dp, i + 1, j + 1);

        dp[i][j] = A[i][j] + min(down, diagonal);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& A) {
        if (A.empty())
            return 0;

        int n = A.size();
        if (n == 1)
            return A[0][0];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(A, dp, 0, 0);
    }
};
