class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            vp[i] = {capital[i], profits[i]};
        }
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && vp[i].first <= w) {
                pq.push(vp[i].second);
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