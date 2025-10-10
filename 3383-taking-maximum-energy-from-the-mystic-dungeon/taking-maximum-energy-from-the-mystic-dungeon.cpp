class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> pref(n, 0);

        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n)
                pref[i] = energy[i] + pref[i + k];
            else
                pref[i] = energy[i];
            ans = max(ans, pref[i]);
        }
        return ans;
    }
};
