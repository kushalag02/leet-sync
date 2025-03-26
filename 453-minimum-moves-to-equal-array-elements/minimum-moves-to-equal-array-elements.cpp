class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int ans = 0;
        for (int i : nums) {
            ans += i;
            ans -= mini;
        }
        return ans;
    }
};