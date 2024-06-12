class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];
        int unique = 9;
        int digits = 9;
        for (int i = 1; i < n; i++) {
            unique *= digits;
            digits--;
        }
        return dp[n] = solve(n - 1, dp) + unique;
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 10;
        return solve(n, dp);
    }
};