bool comparator(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    } else {
        return a[0] < b[0];
    }
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        sort(A.begin(), A.end(), comparator);
        vector<int> dp;
        for (const auto& envelope : A) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return dp.size();
    }
};