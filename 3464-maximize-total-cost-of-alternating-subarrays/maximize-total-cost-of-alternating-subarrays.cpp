class Solution {
public:
    long long solve(int i, int sign, int n, vector<int>& A, vector<vector<long long>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][sign] != -1) {
            return dp[i][sign];
        }
        long long a = 0;
        long long b = 0;
        if (sign == 0) {
            a = A[i] + solve(i + 1, 0, n, A, dp);
            b = -1 * A[i] + solve(i + 1, 1, n, A, dp);
            dp[i][sign] = max(a, b);
        } else {
            a = A[i] + solve(i + 1, 0, n, A, dp);
            dp[i][sign] = a;
        }
        return dp[i][sign];
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return nums[0] + solve(1, 0, n, nums, dp);
    }
};
