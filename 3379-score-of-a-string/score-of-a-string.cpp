class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            ans += abs(s[i + 1] - s[i]);
        }
        return ans;
    }
};