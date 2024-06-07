class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k)
            return false;
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            int curr = itr->first;
            int freq = itr->second;
            if (freq > 0) {
                for (int i = 0; i < k; i++) {
                    if (mp[curr + i] < freq) {
                        return false;
                    }
                    mp[curr + i] -= freq;
                }
            }
        }
        return true;
    }
};