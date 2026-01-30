class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        int n = s.length();

        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, mp[s[i] - 'a']);
            if (i == maxi) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};