class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        sort(begin(worker), end(worker));
        int n = profit.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            vp[i].first = difficulty[i];
            vp[i].second = profit[i];
        }
        sort(vp.begin(), vp.end());
        vector<int> maxi(n);
        maxi[0] = vp[0].second;
        for (int i = 0; i < n - 1; i++) {
            maxi[i + 1] = max(maxi[i], vp[i + 1].second);
        }
        int ans = 0;
        int idx = 0;
        for (int i : worker) {
            while (idx < n && vp[idx].first <= i) {
                idx++;
            }
            if (idx > 0) {
                ans += maxi[idx - 1];
            }
        }
        cout << ans << endl;
        return ans;
    }
};