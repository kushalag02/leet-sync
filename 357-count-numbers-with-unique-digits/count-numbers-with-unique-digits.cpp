class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      // Tabulation
      if(n==0)return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= n; i++) {
            int unique = 9;
            int digits = 9;

            for (int j = 1; j < i; j++) {
                unique *= digits;
                digits--;
            }

            dp[i] = dp[i - 1] + unique;
        }
        return dp[n];
    }
};