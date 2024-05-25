class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int maxi = 1;
        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1] != s[i]) {
                if (s[i + 1] - s[i] == 1) {
                    count++;
                } else {
                    maxi = max(count, maxi);
                    count = 1;
                }
            }
        }
        maxi = max(count, maxi);
        return maxi;
    }
};