class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<pair<int, int>> vp(26, {-1, -1});

        for (int i = 0; i < s.length(); i++) {
            vp[s[i] - 'a'].first = i;
        }
        for (int i = 0; i < t.length(); i++) {
            vp[t[i] - 'a'].second = i;
        }

        int ans = 0;
        for (int i = 0; i < vp.size(); i++) {
            ans += abs(vp[i].first - vp[i].second);
        }

        return ans;
    }
};
