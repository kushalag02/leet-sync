class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        if (n == 1) {
            return scores[0];
        }

        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            vp[i] = {ages[i], scores[i]};
        }

        sort(vp.begin(), vp.end());
        int maxi = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vp[i].second;
            for (int j = i - 1; j >= 0; j--) {
                if (vp[i].second >= vp[j].second) {
                    dp[i] = max(dp[i], dp[j] + vp[i].second);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};