class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int ans = 0;
        while (left < right) {
            ans += nums[right] - nums[left];
            left++;
            right--;
        }
        return ans;
    }
};