class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;

        int count = 0;
        int sum = 0;

        map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum += i;
            if (mp.find(sum - goal) != mp.end()) {
                count += mp[sum - goal];
            }
            mp[sum]++;
        }
        return count;
    }
};