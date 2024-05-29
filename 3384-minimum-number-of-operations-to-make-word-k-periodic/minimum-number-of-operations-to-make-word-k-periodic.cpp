class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        int n = s.size();
        unordered_map<string, int> mp;
        int maxi = 0;

        for (int i = 0; i <= n - k; i += k) {
            string t = s.substr(i, k);
            mp[t]++;
            maxi = max(maxi, mp[t]);
        }

        return n / k - maxi;
    }
};