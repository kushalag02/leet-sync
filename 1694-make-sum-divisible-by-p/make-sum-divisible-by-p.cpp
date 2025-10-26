class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) {
            sum = (sum + i) % p;
        }
        if (sum == 0) {
            return 0;
        }

        // Main logic
        int right = 0;
        unordered_map<int, int> mp = {{0, -1}};

        for (int i = 0; i < nums.size(); i++) {
            right = (right + nums[i]) % p;
            int need = (p - sum + right) % p;
            if (mp.count(need)) {
                n = min(n, i - mp[need]);
            }
            mp[right] = i;
        }
        if (n >= nums.size())
            return -1;
        else
            return n;
    }
};