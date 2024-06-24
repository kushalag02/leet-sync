class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flips -= nums[i - k] / 2;
            }
            if ((nums[i] + flips) % 2 == 0) {
                if (i + k > n) {
                    return -1;
                }
                count++;
                flips++;
                nums[i] += 2;
            }
        }
        return count;
    }
};