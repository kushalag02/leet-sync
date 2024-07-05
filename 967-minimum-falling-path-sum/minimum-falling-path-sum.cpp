class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, solve(matrix, dp, 0, j));
        }
        return ans;
    }

    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i,
              int j) {
        int row = matrix.size();
        int col = matrix[0].size();

        if (j < 0 || j >= col) {
            return INT_MAX;
        }
        if (i == row) {
            return 0;
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        int down = solve(matrix, dp, i + 1, j);
        int left = INT_MAX;
        int right = INT_MAX;
        if (j > 0) {
            left = solve(matrix, dp, i + 1, j - 1);
        }
        if (j < col - 1) {
            right = solve(matrix, dp, i + 1, j + 1);
        }
        return dp[i][j] = matrix[i][j] + min({down, left, right});
    }
};
