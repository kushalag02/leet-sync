class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        bool ans = true;
        int n = nums.size();
        if (n % k != 0)
            return false;
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
            if (mp[i] > n / k)
                ans = false;
        }
        return ans;
    }
};