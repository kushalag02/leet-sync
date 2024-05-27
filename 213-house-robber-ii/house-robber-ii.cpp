class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int first = solve(nums, 0, n - 2);
        int second = solve(nums, 1, n - 1);
        return max(first, second);
    }
    int solve(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = start; i <= end; i++) {
            int curr = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = curr;
        }
        return prev1;
    }
};
