class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        vector<int> dp(n);
        dp[0] = 1;
        int mul2 = 2;
        int mul3 = 3;
        int mul5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = min({mul2, mul3, mul5});

            if (dp[i] == mul2) {
                i2++;
                mul2 = 2 * dp[i2];
            }

            if (dp[i] == mul3) {
                i3++;
                mul3 = 3 * dp[i3];
            }

            if (dp[i] == mul5) {
                i5++;
                mul5 = 5 * dp[i5];
            }
        }

        return dp.back();
    }
};