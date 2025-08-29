class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int m = t.length();

        int ans = 0;
        int j = 0;

        int cost = 0;

        for (int i = 0; i < n; i++) {
            cost += abs(s[i] - t[i]);
            while (cost > maxCost) {
                cost -= abs(s[j] - t[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};