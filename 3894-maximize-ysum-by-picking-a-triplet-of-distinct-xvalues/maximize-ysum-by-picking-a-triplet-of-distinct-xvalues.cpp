#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        if (n < 3)
            return -1;

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({y[i], x[i]});
        }
        unordered_map<int, int> mp;
        long long sum = 0;
        int count = 0;

        while (!pq.empty() && count < 3) {
            int xx = pq.top().second;
            int yy = pq.top().first;
            pq.pop();
            if (mp[xx] == 0) {
                mp[xx] = 1;
                sum += yy;
                count++;
            }
        }

        if (count == 3)
            return sum;
        else
            return -1;
    }
};
