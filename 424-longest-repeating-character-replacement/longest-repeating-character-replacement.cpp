class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        map<char, int> mp;

        int l = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            maxi = max(maxi, mp[s[i]]);

            while (maxi < (i - l + 1) - k) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};