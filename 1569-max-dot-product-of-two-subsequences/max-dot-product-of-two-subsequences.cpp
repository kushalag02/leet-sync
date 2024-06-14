class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        // dp[0][0] = 0;
        return solve(nums1, nums2, n - 1, m - 1, dp);
    }
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return INT_MIN;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int takeBoth = nums1[i] * nums2[j];
        if (i >= 1 && j >= 1)
            takeBoth += max(0, solve(nums1, nums2, i - 1, j - 1, dp));

        int skipNum1 = solve(nums1, nums2, i - 1, j, dp);
        int skipNum2 = solve(nums1, nums2, i, j - 1, dp);

        return dp[i][j] = max({takeBoth, skipNum1, skipNum2});
    }
};
