class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& mp) {
        if (i < 0) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int take = mp[i] + solve(i - 2, dp, mp);
        int skip = solve(i - 1, dp, mp);

        return dp[i] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxi + 1, -1);
        vector<int> mp(maxi + 1, 0);

        for (int x : nums) {
            mp[x] += x;
        }

        return solve(maxi, dp, mp);
    }
};
