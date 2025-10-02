class Solution {
public:
    // Pick two points i and j
    // choose third point k in between
    // Form triangle
    // Split into subproblems
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(0, n - 1, dp, values);
        return ans;
    }

    int solve(int i, int j, vector<vector<int>>& dp, vector<int>& values) {
        if (j - i < 2)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            mini = min(mini, solve(i, k, dp, values) + solve(k, j, dp, values) +
                                 values[i] * values[k] * values[j]);
        }
        return dp[i][j] = mini;
    }
};