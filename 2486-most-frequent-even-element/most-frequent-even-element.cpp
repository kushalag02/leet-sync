class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        int majorE = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                if (nums[i] % 2 == 0) {
                    majorE = nums[i];
                    count++;
                } else {
                    continue;
                }
            }
            if (nums[i] == majorE) {
                count++;
            }
            if (nums[i] != majorE) {
                count--;
            }
        }
        unordered_map<int, int> frequency;
        int maxi = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                frequency[nums[i]]++;
                if (frequency[nums[i]] > maxi) {
                    maxi = frequency[nums[i]];
                    ans = nums[i];
                } else if (frequency[nums[i]] == maxi) {
                    ans = min(ans, nums[i]);
                }
            }
        }
        if (maxi == 0)
            return -1;
        else
            return ans;
    }
};