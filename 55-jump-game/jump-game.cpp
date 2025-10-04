class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, 0);
    }

    bool solve(vector<int>& nums, vector<int>& dp, int pos) {
        int n = nums.size();
        if (pos >= n - 1)
            return true;

        if (dp[pos] != -1)
            return dp[pos];

        int maxi = nums[pos];
        for (int j = 1; j <= maxi; j++) {
            if (solve(nums, dp, pos + j)) {
                dp[pos] = 1;
                return true;
            }
        }

        dp[pos] = 0;
        return dp[pos];
    }
};
