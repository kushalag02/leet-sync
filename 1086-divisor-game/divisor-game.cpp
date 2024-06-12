class Solution {
public:
    bool divisorGame(int n) {
        // if (n % 2)
        //     return false;
        // else
        //     return true;
        vector<bool> dp(n + 1);
        dp[0] = false;
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j * j < i; j++) {
                if (i % j == 0 && dp[i - j] == false)
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};