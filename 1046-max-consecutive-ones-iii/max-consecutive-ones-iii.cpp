class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int count = 0;

            for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            }
            while (count > k) {
                if (nums[l] == 0) {
                    count--;
                }
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};