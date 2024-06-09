class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        // 4 9 9 7 4 5
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            int md;
            if (sum % k == 0) {
                md = 0;
            } else {
                md = (sum < 0) ? k + (sum % k) : sum % k;
            }
            if (mp.find(md) != mp.end()) {
                ans += mp[md];
                mp[md]++;
            } else {
                mp[md]++;
            }
        }
        return ans;
    }
};

