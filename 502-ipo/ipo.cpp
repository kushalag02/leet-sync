bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            vp[i] = {profits[i], capital[i]};
        }
        sort(vp.begin(), vp.end(), comparator);
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && vp[i].second <= w) {
                pq.push(vp[i].first);
                i++;
            }
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};