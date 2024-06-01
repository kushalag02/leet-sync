#define ll long long
class Solution {
public:
    ll minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll ans = abs(nums[n / 2] - k);
        for (int i = n / 2 - 1; i >= 0; i--) {
            if (nums[i] - k > 0)
                ans += nums[i] - k;
        }

        for (int i = n / 2 + 1; i < n; i++) {
            if (k - nums[i] > 0)
                ans += k - nums[i];
        }

        return ans;
    }
};
