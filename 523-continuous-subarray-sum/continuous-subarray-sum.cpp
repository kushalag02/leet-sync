class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        if (nums.size() < 2)
            return false;
        if (nums.size() == 2 && (nums[0] + nums[1]) % k == 0)
            return true;
        if (nums.size() == 2 && (nums[0] + nums[1]) % k != 0)
            return false;
        prefix[0] = nums[0];
        for (int i = 0; i < n - 1; i++) {
            prefix[i + 1] = prefix[i] + nums[i + 1];
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            int rem = prefix[i] % k;
            if (rem < 0)
                rem += k;

            auto itr = mp.find(rem);
            if (itr != mp.end()) {
                if (i - itr->second > 1)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
        // 23 25 29 35 42
    }
};