#define ll long long

ll log4(ll a) { return log2(a) / log2(4); }

class Solution {
public:
    ll minOperations(vector<vector<int>>& queries) {
        ll mx = 0;
        ll ans = 0;
        for (auto p : queries)
            mx = max(mx, 1LL * p[1]);

        vector<ll> pw = {1};
        ll no = 1;
        while (no <= mx) {
            no *= 4;
            pw.push_back(no);
        }

        for (auto query : queries) {
            ll l = query[0];
            ll r = query[1];
            ll llog = log4(l);
            ll rlog = log4(r);
            if (llog == rlog) {
                ll cnt = r - l + 1;
                ans += (cnt * (llog + 1) + 1) / 2;
                continue;
            }

            ll totalSteps = 0;
            for (ll i = llog + 1; i <= rlog + 1; i++) {
                ll lastNum = min(pw[i] - 1, r);
                ll cnt = lastNum - l + 1;
                totalSteps += cnt * i;
                l = lastNum + 1;
            }
            ans += (totalSteps + 1) / 2;
        }
        return ans;
    }
};